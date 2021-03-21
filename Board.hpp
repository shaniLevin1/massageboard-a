#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;
namespace ariel{

    class Board{
        uint row;
        uint col;
        vector<vector<char>> m;

        public:
            Board(){
                row=1;
                col=1;
                m=vector<vector<char>>(1,vector<char>(1,'_'));
            }
            void post(uint i, uint j, ariel::Direction d, string s);
            string read(uint i, uint j, ariel::Direction d, uint k);
            void show();
    };
}