/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-27 03:20
# Email        : lio_h_zen@163.com
# Filename     : ConfigParser.h
# Description  : 
******************************************************/

#ifndef LZC_CONFIGPARSER_H
#define LZC_CONFIGPARSER_H

#include "common.h"
#include "string.h"

namespace lzc {

struct ConfigItem {
    std::string value;
    ConfigItem(const std::string &val): value(val) {}
    int to_int32() const {
        CHECK(!value.empty());
        return std::move(stoi(value));
    }
    std::string to_string() const {
        CHECK(!value.empty());
        return value;
    }
    bool to_bool() const {
        CHECK(!value.empty());
        CHECK(value == "true" || value == "false" );
        if (value == "true")
            return true;
        return false; 
    }
}; // struct ConfigItem

class ConfigParser : public NoncopyableObject {
public:
    ConfigParser(const std::string& conf_path): _conf_path(conf_path) {
        parse(); 
    }

    void register_config(const std::string &key, const std::string &value="") {
        CHECK(!key.empty());
        CHECK(_unmap.count(key) == 0) << "duplicate key value:\t" << key; 
        _unmap.insert({std::move(key), ConfigItem(value)});
    }
    const ConfigItem& get_config(const std::string &key) {
        auto p = _unmap.find(key);
        CHECK(p != _unmap.end()) << "key value not found\t" << key;
        return p->second;
    }

private: 
    std::unordered_map<std::string, ConfigItem> _unmap;
    std::string _conf_path;

    void parse() {
        LOG(INFO) << "loading from : " << _conf_path;
        parse_conf(_conf_path);
    }

    void parse_conf(std::string conf_path) {
        std::string line;
        std::ifstream fd(conf_path);
        CHECK(fd.is_open()) << "failed to open config file, path is:" << _conf_path;        
        while (getline(fd, line)) {
            trim(line);
            if (starts_with(line, "#")) continue;
            if (starts_with(line, "import")) {
                std::pair<std::string, std::string> ps = kv_split(line, " ");
                LOG(INFO) << "start to loading from " << ps.second;
                parse_conf(ps.second); 
                LOG(INFO) << "loaded from " << ps.second;
                continue;
            }
            std::pair<std::string, std::string> ps = kv_split(line, ":");
            register_config(ps.first, ps.second);
        }
    }
}; // class ConfigParser

} // namespace lzc
#endif
