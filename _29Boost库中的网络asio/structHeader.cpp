#include "structHeader.h"



bool paresMessage(const std::string& input, int* type, std::string& outbuffer)
{
    auto pos = input.find_first_of(" ");
    if (pos == std::string::npos)
        return false;
    if (pos == 0)
        return false;

    auto command = input.substr(0, pos);
    if (command == "BindName")
    {
        std::string name = input.substr(pos + 1);
        if (name.size() > 32)
            return false;
        if (type)
            *type = 1;
        BindName bindInfo;
        bindInfo.nameLen = name.size();
        std::memcpy(&(bindInfo.name), name.data(), name.size());
        auto buffer = reinterpret_cast<const char*>(&bindInfo);
        outbuffer.assign(buffer, buffer + sizeof(bindInfo));
        return true;
    }
    else if(command == "Chat") {
        std::string chat = input.substr(pos + 1);
        if (chat.size() > 256) {
            return false;
        }
        ChatInfomation info;
        info.infoLen = chat.size();
        std::memcpy(&(info.infomation), chat.data(), chat.size());
        auto buffer = reinterpret_cast<const char*>(&info);
        outbuffer.assign(buffer, buffer + sizeof(info));
        if (type) {
            *type = 2;
        }
        return true;
    }
    return false;
}
