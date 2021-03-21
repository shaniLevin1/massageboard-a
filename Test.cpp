
#include "Board.hpp" 
#include "doctest.h"
using namespace std;
using namespace ariel;

Board board;

TEST_CASE("read before post and out of bound"){
    CHECK(board.read(0,4,Direction::Horizontal,3)==string("___"));
    CHECK(board.read(3,5,Direction::Horizontal,1)==string("_"));
    CHECK(board.read(1,2,Direction::Horizontal,5)==string("_____"));
    CHECK(board.read(6,3,Direction::Vertical,2)==string("__"));
    CHECK(board.read(8,9,Direction::Vertical,4)==string("____"));
    CHECK(board.read(4,7,Direction::Vertical,7)==string("_______"));
}

//12X9
TEST_CASE("post"){
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"The"));
    CHECK_NOTHROW(board.post(0,4,Direction::Horizontal,"cat"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"This"));
    CHECK_NOTHROW(board.post(5,0,Direction::Vertical,"dog"));
}

TEST_CASE("post and read"){
    CHECK(board.read(0,0,Direction::Horizontal, 3)==string("The"));
    CHECK(board.read(0,0,Direction::Horizontal, 7)==string("The_cat"));
    CHECK(board.read(0,4,Direction::Horizontal,3)==string("cat"));
    CHECK(board.read(0,0,Direction::Vertical,4)==string("This"));
    CHECK(board.read(0,0,Direction::Vertical,6)==string("This_d"));
    CHECK(board.read(5,0,Direction::Vertical,3)==string("dog"));
    CHECK(board.read(5,0,Direction::Vertical,6)==string("dog___"));
}
//12X9 
TEST_CASE("read->out of board bounds"){
    CHECK_NOTHROW(board.post(10,9,Direction::Horizontal,"The"));
    CHECK(board.read(11,9,Direction::Horizontal, 3)==string("he_"));
//12X12
    CHECK_NOTHROW(board.post(0,10,Direction::Horizontal,"The"));
    CHECK(board.read(0,11,Direction::Horizontal, 3)==string("he_"));
}

TEST_CASE("read->iterapt"){
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"The"));
    CHECK_NOTHROW(board.post(0,1,Direction::Vertical,"cat"));
    //Tce
    //_a_
    //_t_
    CHECK(board.read(0,1,Direction::Horizontal, 1)==string("c"));
    CHECK_NOTHROW(board.post(3,3,Direction::Horizontal,"This"));
    //Tce
    //_a_
    //_tThis
    CHECK_NOTHROW(board.post(3,5,Direction::Vertical,"dog"));
    //Tce
    //_a_
    //_tThds
    //____o_
    //____g_
    CHECK(board.read(3,5,Direction::Horizontal, 1)==string("d"));
    CHECK(board.read(4,5,Direction::Horizontal, 3)==string("og_"));
}



TEST_CASE("read-> string length is 0"){
    CHECK(board.read(0,0,Direction::Horizontal, 0)==string(""));
    CHECK(board.read(3,6,Direction::Horizontal, 0)==string(""));
    CHECK(board.read(5,4,Direction::Vertical,0)==string(""));
    CHECK(board.read(8,3,Direction::Vertical,0)==string(""));
    CHECK(board.read(2,7,Direction::Vertical,0)==string(""));
    CHECK(board.read(9,9,Direction::Vertical,0)==string(""));
}







