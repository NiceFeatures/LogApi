#pragma once

struct P_CURL_MOD_MEMORY {
  char *Memory;
  size_t Size;
  int EventIndex;
  struct curl_slist *Headers;
  std::string Url;
  std::string PostData;
  std::string BearerToken;
  long Timeout;
  bool Retried;
};

class CLogCurl {
public:
  void ServerActivate();
  void ServerFrame();

  void PostJSON(const char *url, long Timeout, std::string BearerToken,
                std::string PostData, int EventIndex, bool Retried = false);

  static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb,
                                    void *userp);

  bool HasSystemCaBundle();

private:
  CURLM *m_MultiHandle = NULL;

  long m_RequestIndex = 0;

  bool m_SslFallback = false;

  std::string m_CaBundlePath;

  std::map<long, P_CURL_MOD_MEMORY> m_Data;
};

extern CLogCurl gLogCurl;
