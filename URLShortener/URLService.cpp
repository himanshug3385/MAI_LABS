#include<bits/stdc++.h>
using namespace std;

class URLService{
    private:
     unordered_map<string,string>urlMap;
     unordered_map<string,int>domainCount;
     string base_url="http://short.ly";
     string getUniqueId(){
        return "";
     }
     string getUrlDomain(string url){
        return "";
     }
    public:
    URLService(){
        urlMap.clear();
        domainCount.clear();
    }
    //POST API for shorten the larger URL - /shorten
    pair<string,string> shortenUrl(unordered_map<string,string>request){
        string originalUrl=request["url"];
        string shortUrlId=getUniqueId();
        urlMap[shortUrlId]=originalUrl;
        string domain=getUrlDomain(originalUrl);
        domainCount[domain]++;
        pair<string,string>response;
        response=make_pair("shortUrl",base_url+shortUrlId);
        return response;
    }
    // GET API for redirecting to long url - /{shortUrlId}
    string redirectUrl(string shortUrlId){
        if(urlMap.find(shortUrlId)==urlMap.end())
        return "URL not found";
        return urlMap[shortUrlId];
    }

}
