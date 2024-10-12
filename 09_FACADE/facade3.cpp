#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

class NetworkInit
{
public:
	NetworkInit()
	{
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		WSACleanup();
	}
};

class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

class TCPServer // 반복되는것, 내부동작을 알 필요가 없는 동작은 다음과 같이 싸주는 것이 좋다.
{
	NetworkInit init;
	Socket sock{SOCK_STREAM};
public:
	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{
	TCPServer server; // 파사드. 이련의 절차에 대한 포괄적인 개념의 인터페이스를 제공 >> 사용자가 사용이 쉬워짐 
	server.Start("127.0.0.1", 4000);
}