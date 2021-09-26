// https://replit.com/@cchuanqi/Permutation-1#main.cpp
#include <iostream>
#include <vector> 
#include <string> 
#include <algorithm>

using namespace std; 

vector<string> permutate(vector<string> vec1, char c)
{
  vector<string> vec2; 
  for(int i=0; i<vec1.size(); i++)
  {
    string st= vec1[i]; 
    for(int i=0; i<=st.size(); i++)
    {
      string tmp = st; 
      tmp.insert(i, 1, c); 
      vec2.push_back(tmp); 
    }
  }

  return vec2; 
}

int main() {
  int n; 
  cin >> n; 
  string seq; 
  for(int i=1; i<=n; i++)
    seq +=std::to_string(i);   

  vector<string> perms; 
  perms.push_back(std::to_string(1));
  for(int i=1; i<n; i++)
  {
    perms = permutate(perms, seq[i]); 
  }

  sort(perms.begin(), perms.end());

  for(vector<string>::iterator it = perms.begin(); it<perms.end(); it++)
  {
    string item = *it;
    for(int i=0; i<item.size(); i++)
      cout << item[i] << " ";
    cout << endl;  
  }

  return 0; 
}

// https://replit.com/@cchuanqi/Permutation-1#main_swap.cpp
#include <iostream>
#include <vector> 
#include <string> 
#include <algorithm>

using namespace std; 
vector<string> perms; 

void permute2(string& a, int l, int r)
{
  if( l== r )
  {
    perms.push_back(a); 
    return; 
  }

  for(int i=l; i<=r; i++)
  {
    // Swapping done
    swap(a[l], a[i]); 

    // Resursion 
    permute2(a, l+1, r); 

    // backtrack 
    swap(a[l], a[i]); 
  }

  return; 
}

int main2() {
  int n; 
  cin >> n; 
  string seq; 
  for(int i=1; i<=n; i++)
    seq +=std::to_string(i);   

  permute2(seq, 0, seq.size()-1); 
 

  sort(perms.begin(), perms.end());

  for(vector<string>::iterator it = perms.begin(); it<perms.end(); it++)
  {
    string item = *it;
    for(int i=0; i<item.size(); i++)
      cout << item[i] << " ";
    cout << endl;  
  }

  return 0; 
}