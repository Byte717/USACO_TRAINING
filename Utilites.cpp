#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

template<class T> class utilites{
    int n;
    bool debug;
    int m;
    const int dirX[] = {-1, 0, 1, 0};
    const int dirY[] = {0, 1, 0, -1};
    public:


        utilites(const int &n1, const bool &d, const int &m1= -1){
            n = n1;
            debug = d;
            m = (m1 > 0) ? m1 : n;
        }

        int LOG2(const int &n){
            int ret = 0; 
            while((1<<(ret+1)) <= n){ret++;}
            return ret;
        }
        
        bool InBounds(const T &x1, const T &y1){return x1 < n && x1 >= 0 && y1 >= 0 && y1 < m;}


        void fast(){
            cin.tie(0)->sync_with_stdio(0);
        }

        void SetIo(const string &name = "", bool fast = false){
            if(fast){fast();}
            if(debug && name.size()){
                freopen(name,"r",stdin);
            }
        }
        vector<T> coordinateCompression(vector<T> a){
            // idx of each element in a sorted list;
            // to be implemented later;
        }

        unsigned long long distanceSquared(const T &x1, const T &y1, const T &x2, const T &y2){
            return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        }
        int len(auto t){
            return t.size();
        }
        vector<pair<int,int>> adjacent(int x, int y){
            vector<pair<int,int>> ret;
            for(int i = 0; i < 4;i++){
                int newX = x+dirX[i], newY = y+dirY[i];
                ret.push_back({newX,newY});
            }
            return ret;
        }
        
};


class InputParser{
    public:
        InputParser (int &argc, char **argv, char **envp){
            for (int i=1; i < argc; ++i) this->tokens.push_back(std::string(argv[i]));
            for(int i = 0; envp[i] != nullptr; ++i){
                auto tmp = std::string(envp[i]);
                size_t pos = tmp.find('=');
                this->envTokens[tmp.substr(0,pos)] = tmp.substr(pos+1);
            }
        }

        const std::string& getCmdOption(const std::string &option) const{
            std::vector<std::string>::const_iterator itr;
            itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
            if (itr != this->tokens.end() && ++itr != this->tokens.end()){
                return *itr;
            }
            static const std::string empty_string("");
            return empty_string;
        }

        const std::string& getEnvOption(const std::string &option) const{
            if(!this->envOptionExists(option)){ // dne
                return std::string("");
            }
            return this->envTokens.find(option)->second;
        }

        bool cmdOptionExists(const std::string &option) const{
            return std::find(this->tokens.begin(), this->tokens.end(), option)
                   != this->tokens.end();
        }

        bool envOptionExists(const std::string &param) const{
            return this->envTokens.find(param) != this->envTokens.end();
        }
    private:
        std::vector <std::string> tokens;
        std::unordered_map <std::string, std::string> envTokens;
};
