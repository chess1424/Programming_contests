#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  long long n, queries, l, r, k, prev_num, num, key, frec, sub_l, max_frec;


  while(scanf("%lld %lld",&n,&queries) != EOF)
  {

    scanf("%lld",&prev_num);
    key = prev_num;
    frec = 1;
    max_frec = frec;
    map<long long , vector< pair<long long, pair<long long, long long > > > >m;
    sub_l = 0;

    for(long long i = 1; i < n; i++)
    {
      scanf("%lld",&num);
      if(num == prev_num)
        frec++;
      else
      {
        max_frec = max(max_frec, frec);
        m[frec].push_back(make_pair(key, make_pair(sub_l, i-1)));
        prev_num = num;
        key = prev_num;
        frec = 1;
        sub_l = i;
      }
    }
    m[frec].push_back(make_pair(key, make_pair(sub_l, n-1)));
    max_frec = max(max_frec, frec);


    for(long long i = 0; i < queries; i++)
    {
      scanf("%lld %lld %lld",&l,&r,&k);

      l--;
      r--;

      if(k > max_frec)
      {
        printf("-1\n");
        continue;
      }

      bool ans = false;
      long long ans_key = -1;

      for(map<long long , vector< pair<long long, pair<long long, long long > > > >::iterator it = m.begin(); it != m.end() && !ans; ++it)
      {

        for(long long j = 0; j < it -> second.size() && !ans; j++)
        {

          if(it -> second[j].second.second < l || it -> second[j].second.first > r) continue;// lr[] || []lr
          else if(it ->second[j].second.second <= r && it ->second[j].second.first < l)//l[r]
          {
            if(it ->second[j].second.second - l + 1 >= k)
            {
              ans = true;
              ans_key =  it ->second[j].first;
            }
          }
          else if(it ->second[j].second.first >= l && it ->second[j].second.second > r)//[l]r
          {
            if(r - it->second[j].second.first + 1 >= k)
            {
              ans = true;
              ans_key = it ->second[j].first;
            }
          }
          else if(it ->second[j].second.first < l && it ->second[j].second.second > r)//l[]r
          {
            if(r - l + 1 >= k)
            {
              ans = true;
              ans_key = it ->second[j].first;
            }
          }
          else
          {
            if(it->second[j].second.second - it->second[j].second.first + 1 >= k)//[lr]
            {
              ans = true;
              ans_key = it->second[j].first;
            }
          }
        }
      }

      cout << ans_key << endl;
    }


  }
  return 0;
}