#include"stdio.h"
#include"iostream"
#include"boost/regex.hpp"
#include"boost/asio.hpp"
int argc(){
	char const* argv[]
	using namespace boost::asio;
	using namespace std;
	// Julius の ip と port を指定
	const std::string ip = "192.168.0.10";
	const int port       = 10500;
	// Julius へ接続
	ip::address addr = ip::address::from_string(ip);
	ip::tcp::endpoint ep(addr, port);
	ip::tcp::iostream s(ep);
	// Julius サーバ 起動
	s << "STATUS\n" << std::flush;
	// 応答を解析する正規表現
	boost::regex r("WORD=\"([^\"]+)\"");
	boost::smatch m;
	// Julius からの応答を解析
	string line, word;
}
int main(){        
while(getline(s,line)) {
                if (boost::regex_search(line, m, r)){
			word += m.str(1);
		else if (line.find("<RECOGOUT>") != npos)
			word = "";
		else if (line.find("</RECOGOUT>") != npos)
			cout << word << endl;
	}
	return 0;
}