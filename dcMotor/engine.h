#ifndef __ENGINE__
#define __ENGINE__


class Engine
{
    public:	
        virtual ~Engine(); 		   						
    	virtual void control( int demanded_speed ) = 0;
};

#endif 
