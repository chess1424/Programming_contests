#include <iostream>

#define maxBits 62

typedef long long int ll;

using namespace std;


ll f(const ll &target, const ll &cnt1, const ll &cnt2, const ll &x, const ll &y)
{
  ll withoutX    = target - (target/x);
  ll withoutY    = target - (target/y);
  ll withoutBoth = target - target/(x*y);

  return withoutBoth >= cnt1+cnt2 && withoutX >= cnt1 && withoutY >= cnt2;
}

ll solve(const ll &cnt1, const ll &cnt2, const ll &x, const ll &y)
{
  ll ans = (1LL<<maxBits) - 1LL;
  for(int i = maxBits - 1; i >= 0; i--)
    ans ^= f(ans ^ (1LL<<i), cnt1, cnt2, x , y) << i;

  return ans;
}

int main()
{
  ll cnt1, cnt2, x, y, n;

  while(cin >> cnt1 >> cnt2 >> x >> y)
    cout << solve(cnt1, cnt2, x, y) << '\n';

  return 0;
}
