<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<header>
        <h1>URL Shortener Service</h1>
    </header>

<main>
        <section>
            <h2 class="section-title">Features</h2>
            <ul>
                <li><strong>Shorten URL:</strong> Shorten long URLs to a shortened version.</li>
                <li><strong>Redirect to Long URL:</strong> Redirect to the original long URL from the shortened URL.</li>
                <li><strong>Top Domains:</strong> View the top 3 most frequently used domains based on shortened URLs.</li>
            </ul>
        </section>

  <section>
            <h2 class="section-title">API Endpoints</h2>
            <h3>1. POST /shorten</h3>
            <p>Shorten a long URL:</p>
            <pre><code>{
    "url": "https://example.com/verylongurl"
}</code></pre>
            <p>Response:</p>
            <div class="response-example">
                <pre><code>{
    "shortUrl": "http://short.ly/abcd123"
}</code></pre>
            </div>

<h3>2. GET /{shortUrlId}</h3>
            <p>Redirect to the long URL using the short URL ID.</p>
            <p>Request:</p>
            <pre><code>GET /abcd123</code></pre>
            <p>Response:</p>
            <div class="response-example">
                <p>Redirect to <code>https://example.com/verylongurl</code>.</p>
            </div>

 <h3>3. GET /top-domains</h3>
            <p>Get the top 3 most frequently used domains.</p>
            <div class="response-example">
                <pre><code>[
    {
        "domain": "udemy.com",
        "count": 4
    },
    {
        "domain": "wikipedia.com",
        "count": 4
    },
    {
        "domain": "youtube.com",
        "count": 1
    }
]</code></pre>
            </div>
        </section>

<section>
            <h2 class="section-title">How It Works</h2>
            <p><strong>Shortening a URL:</strong> A random 7-character string is generated to act as the shortened URL ID.
                The domain of the long URL is extracted, and its count is incremented. The shortened URL is returned to the
                user.</p>
            <p><strong>Redirecting to the Long URL:</strong> Given a shortened URL, the service looks it up in the
                <code>urlMap</code> and redirects the user to the original URL.</p>
            <p><strong>Tracking Top Domains:</strong> Every time a URL is shortened, its domain’s count is updated in
                <code>domainCountMap</code>. The priority queue <code>domainCount</code> is used to track and return the
                top domains based on usage.</p>
        </section>

<section>
            <h2 class="section-title">Example Usage</h2>
            <div class="example">
                <pre><code>URLService urlService;

// Shorten a URL
unordered_map<string, string> request;
request["url"] = "https://youtube.com/abcbdbddd";
pair<string, string> response = urlService.shortenUrl(request);
cout << response.first << " -> " << response.second << endl;  // Output: shortUrl -> http://short.ly/abcd123

// Redirect to the long URL using the shortened URL
string longUrl = urlService.redirectUrl(response.second);
cout << response.second << " => long URL: " << longUrl << endl;  // Output: http://short.ly/abcd123 => https://youtube.com/abcbdbddd

// Get top 3 domains
vector<pair<string, int>> top3Domains = urlService.getTopDomains();
for (auto domain : top3Domains) {
    cout << domain.first << " " << domain.second << endl;
}</code></pre>
            </div>
        </section>

  <section>
            <h2 class="section-title">Requirements</h2>
            <ul>
                <li>C++11 or later</li>
                <li>A C++ compiler that supports <code>std::unordered_map</code> and <code>std::priority_queue</code></li>
            </ul>
        </section>
    </main>

</body>

</html>
