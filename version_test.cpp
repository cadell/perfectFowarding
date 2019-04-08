//#include <iostream>
//
//
template<unsigned dim>
struct vec
{
    float d[dim];

    template<typename ... T>
    vec(T&& ... args) : d{args... } {}  /*The concept of constuctor() :d{} { ///constructor body here ....}
                                        //this is an initializer list it will initalize the generic parameters in our variable 
                                        // the three dots allows you to have multiple parameters, meaning that multiple values
                                        // get forwared to our d array hense the value of dim is the amount of parameters we pass to our vec constructor */
    float operator[] (unsigned n) const {return d[n];} 
    auto CrossProduct(const vec& b) const
    {
        //Normally this func cannot return values of different types 
        //however in cpp 17 we can evaluate the if as a constexpr which makes it a compile-time conditon
        //allowing it to determine it's return type during compile time?
        if constexpr(dim == 2) 
        {
            return d[0]*b[1] - d[1]*b[0];            
        }
        if constexpr(dim == 3)
        {
            return vec<3>{d[1]*b[2]-d[2]*b[1], d[2]*b[0]-d[0]*b[2], d[0]*b[1]-d[1]*b[0]};
        }
    }
            
};

int main ()
{
    vec<2> xy1{1.f, 2.f}, xy2{3.f, 4.f};
    vec<3> xyz1{5.f, 6.f, 7.f}, xyz2{8.f, 9.f, 10.f};

    float res1 = xy1.CrossProduct(xy2);
    auto  res2 = xyz1.CrossProduct(xyz2);  
}
