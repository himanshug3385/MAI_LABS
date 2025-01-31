#include <bits/stdc++.h>
using namespace std;

class URLService
{
private:
    unordered_map<string, string> urlMap;
    priority_queue<pair<int, string>> domainCount;
    unordered_map<string, int> domainCountMap;
    string base_url = "http://short.ly";

    string getUniqueId()
    {
        string id = "";
        const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int charsetSize = sizeof(charset) - 1;

        for (int i = 0; i < 7; ++i)
        {
            id += charset[rand() % charsetSize];
        }

        return id;
    }
    string getUrlDomain(string url)
    {
        regex urlPattern(R"(https?:\/\/([^\/]+))");
        smatch match;
        if (std::regex_search(url, match, urlPattern))
        {
            return match[1]; // Extract domain
        }
        return "Invalid URL";
    }

public:
    URLService()
    {
        urlMap.clear();
        domainCountMap.clear();
        while (!domainCount.empty())
            domainCount.pop();
    }
    // POST API for shorten the larger URL - /shorten
    pair<string, string> shortenUrl(unordered_map<string, string> request)
    {
        string originalUrl = request["url"];
        string shortUrlId = getUniqueId();
        urlMap[shortUrlId] = originalUrl;
        string domain = getUrlDomain(originalUrl);
        domainCountMap[domain]++;
        domainCount.push({domainCountMap[domain], domain});
        pair<string, string> response;
        response = make_pair("shortUrl", base_url + shortUrlId);
        return response;
    }
    // GET API for redirecting to long url - /{shortUrlId}
    string redirectUrl(string shortUrlId)
    {
        if (urlMap.find(shortUrlId) == urlMap.end())
            return "URL not found";
        return urlMap[shortUrlId];
    }
    // GET API for getting 3 top Domains - /top-domains
    vector<pair<string, int>> getTopDomains()
    {
        int count = 0;
        vector<pair<string, int>> response;
        priority_queue<pair<int, string>> copyDomainCount = domainCount;
        while (!copyDomainCount.empty() and count < 3)
        {
            string domain = copyDomainCount.top().second;
            int occurence = copyDomainCount.top().first;
            if (occurence == domainCountMap[domain])
                count++;
            copyDomainCount.pop();
            response.push_back({domain, occurence});
        }
        return response;
    }
};

int main()
{
    URLService urlService;
    unordered_map<string, string> request;
    request["url"] = "https://youtube.com/abcbdbddd";
    pair<string, string> response = urlService.shortenUrl(request);
    cout << response.first << "->" << response.second << endl;
    request["url"] = "https://udemy.com/fhldfhhf";
    pair<string, string> response2 = urlService.shortenUrl(request);
    request["url"] = "https://udemy.com/fallsaslh";
    pair<string, string> response3 = urlService.shortenUrl(request);
    request["url"] = "https://udemy.com/fallsaslh";
    pair<string, string> response4 = urlService.shortenUrl(request);
    request["url"] = "https://udemy.com/qewepoiii";
    pair<string, string> response5 = urlService.shortenUrl(request);
    request["url"] = "https://wikipedia.com/SSCCasak";
    pair<string, string> response6 = urlService.shortenUrl(request);
    request["url"] = "https://wikipedia.com/nnAADnm";
    pair<string, string> response7 = urlService.shortenUrl(request);
    request["url"] = "https://wikipedia.com/eqopeasas";
    pair<string, string> response8 = urlService.shortenUrl(request);
    request["url"] = "https://wikipedia.com/sksnsSA";
    pair<string, string> response9 = urlService.shortenUrl(request);
    request["url"] = "https://wikipedia.com/ASASFalask";
    pair<string, string> response10 = urlService.shortenUrl(request);

    string shorturlid = urlService.redirectUrl("ASASFalask");
    cout << "ASASFalask => long url" << shorturlid << endl;

    vector<pair<string, int>> top3Domains = urlService.getTopDomains();
    for (auto domain : top3Domains)
    {
        cout << domain.first << " " << domain.second << endl;
    }
    return 0;
}