#include <cxxtest/TestSuite.h>
#include <world/room.hpp>


class TestRoom : public CxxTest::TestSuite
{
   public:

      void testgetXandY( void )
      {
         world::Room room( 2, 3 );
         TS_ASSERT( room.get_x() == 2 );
         TS_ASSERT( room.get_y() == 3 );
      }

      void test_instance_variables_val( void ){
         world::Room room( 2, 3 );
         room.wumpus = 1;
         room.breeze = 1; 
         TS_ASSERT( room.wumpus == 1 );
         TS_ASSERT( room.breeze == 1 );
         TS_ASSERT( room.agent == 0);
      }

};