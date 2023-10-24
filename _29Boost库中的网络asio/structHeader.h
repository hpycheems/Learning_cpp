#pragma once
#include <string>

struct Header
{
	int bodySize;
	int type;
};
struct BindName
{
	char name[32];
	int nameLen;
};
struct ChatInfomation
{
	char infomation[256];
	int infoLen;
};
struct RoomInfomation
{
	BindName name;
	ChatInfomation chat;
};
bool paresMessage(const std::string& input, int* type, std::string& outbuffer);