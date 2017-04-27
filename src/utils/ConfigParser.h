#ifndef LZC_CONFIGPARSER_H
#define LZC_CONFIGPARSER_H

namespace lzc {

struct ConfigItem {
    std::string value;
    ConfigItem(const std::string &val) value(val) {}
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
    void register_config(const std::string &key, const std::string &value="") {
        CHECK(!key.empty());
        CHECK(_unmap.count(key) == 0) << "duplicate key value:\t" << key; 
        _unmap.insert({std::move(key), ConfigItem(value)});
    }
    const ConfigItem& get_config(const std::string &key) {
        auto p = _unmap.find(key);
        CHECK(p != _unmap.end()) << "key value not found\t" << key;
        return p.second;
    }
private: 
    std::unordered_map<std::string, ConfigItem> _unmap;
}; // class ConfigParser

} // namespace lzc
