#include <stdlib.h>
#include <cstdio>
#include <algorithm>



template <typename typeOfData> 
class Vector
	{
	public:
		Vector ( size_t reservedCapacityTemp )
			{
			reservedCapacity = reservedCapacityTemp;
			init();
			}



		size_t reservedCapacity = NULL;
		typeOfData* storage = nullptr;

		size_t currentIndex = NULL;

		void init()
			{
			storage = new typeOfData [ reservedCapacity ]{};
			}

		void push_back ( typeOfData element )
			{
			if ( currentIndex < reservedCapacity )
				{
				storage [ currentIndex ] = element;
				currentIndex++;
				}
			else
				{
				renewStorage();
				storage [ currentIndex ] = element;
				currentIndex++;
				}
			}

		void pop()
			{
			if ( currentIndex != 0 )
				{
				currentIndex--;
				}
			}

		typeOfData top()
			{
			return ( currentIndex != 0 ) ? storage [ ( currentIndex - 1 ) ] : NULL;
			}

		typeOfData back()
			{
			return ( currentIndex != 0 ) ? storage [ 0 ] : NULL;
			}

		typeOfData operator[] ( size_t index )
			{
			return getValueByIndex ( index );
			}

		typeOfData at ( size_t index )
			{
			return getValueByIndex ( index );
			}

		typeOfData getValueByIndex ( size_t index )
			{
			if ( ( index < currentIndex ) && ( index >= 0 ) )
				{
				return storage [ index ];
				}
			else
				{
				return NULL;
				}
			}

		void renewStorage()
			{
			typeOfData* buffer = new typeOfData [ ( reservedCapacity + 10 ) ]{};
			
			for ( int i = 0; i < reservedCapacity; i++ )
				{
				buffer [ i ] = storage [ i ];
				}

            delete[] storage;
            
            reservedCapacity = ( reservedCapacity + 10 );
            
			storage = buffer;
			}

		typeOfData* begin()
			{ 
			return storage;
			}
		typeOfData* end()
			{
			return ( storage + currentIndex );
			}

		const typeOfData* begin() const
			{
			return storage;
			}
		const typeOfData* end()	const
			{
			return ( storage + currentIndex );
			}
		

	};



int main()
	{
	Vector <int> myVector ( 10 );
	
	myVector.push_back ( 4 );
	myVector.push_back ( 5 );
	myVector.push_back ( 7 );
	myVector.push_back ( 1 );
	myVector.push_back ( 5 );
	myVector.push_back ( 9 );
	myVector.push_back ( 5 );
	myVector.push_back ( 6 );
    myVector.push_back ( 5 );
    myVector.push_back ( 7 );
    myVector.push_back ( 1 );
    myVector.push_back ( 5 );
    myVector.push_back ( 9 );
    myVector.push_back ( 5 );
    myVector.push_back ( 6 );   
    myVector.push_back ( 4 );
    myVector.push_back ( 5 );
    myVector.push_back ( 7 );
    myVector.push_back ( 1 );
    myVector.push_back ( 5 );
    myVector.push_back ( 9 );
    myVector.push_back ( 5 );
    myVector.push_back ( 6 );
    myVector.push_back ( 5 );
    myVector.push_back ( 7 );
    myVector.push_back ( 1 );
    myVector.push_back ( 5 );
    myVector.push_back ( 9 );
    myVector.push_back ( 5 );
    myVector.push_back ( 6 );
    myVector.push_back ( 1 );
    myVector.push_back ( 5 );
    myVector.push_back ( 9 );
    myVector.push_back ( 5 );
    myVector.push_back ( 6 );

//    printf ( "%d %d %d\n", myVector.back(), myVector.at ( 5 ), myVector.top() );
	
	for ( int i = 0; i < 35; i++ )
		{
		printf ( "%d ", myVector [ i ] );
		}
	
//    std::sort ( myVector.begin(), myVector.end() );
//    for ( auto temp : myVector )
//        {
//        printf ( "%d ", temp );
//        }

//    getchar();

	return 0;
	}
