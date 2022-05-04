#include "../src/vector.h"
#include <cmath>
TEST(CHKDEFCONSTR,case1){
    Vector v1;
    ASSERT_EQ(0,v1.dim());
}
TEST(CHKDIM, case1){
    double a[3] ={1,2,3};
    Vector t1=Vector(a,3);
    ASSERT_EQ(3,t1.dim());
}
TEST(CHKAT, case1){
    double a[3] ={1,2,3};
    Vector t1=Vector(a,3);
    ASSERT_NEAR(3,t1.at(3),0.5f);
}
TEST(CHKSUBFUNC, case1){
    double a[3] ={1,2,3};
    double b[3] ={0,1,1};
    Vector t1=Vector(a,3);
    Vector t2=Vector(b,3);
    t1.subtract(t2);
    ASSERT_NEAR(2,t1.at(3),0.5f);
}
TEST(CHKSUBFUNC, case2){
    double a[4] ={1,2,3,4};
    double b[3] ={0,1,1};
    Vector t1=Vector(a,4);
    Vector t2=Vector(b,3);
    ASSERT_ANY_THROW(t1.subtract(t2));
}
TEST(CHKADDFUNC, case1){
    double a[3] ={1,2,3};
    double b[3] ={0,1,1};
    Vector t1=Vector(a,3);
    Vector t2=Vector(b,3);
    t1.add(t2);
    ASSERT_NEAR(4,t1.at(3),0.5f);
}
TEST(CHKADDFUNC, case2){
    double a[4] ={1,2,3,4};
    double b[3] ={0,1,1};
    Vector t1=Vector(a,4);
    Vector t2=Vector(b,3);
    ASSERT_ANY_THROW(t1.add(t2));
}
TEST(CHKSUB, case1){
    double a[3] ={1,2,3};
    double b[3] ={0,1,1};
    Vector t1=Vector(a,3);
    Vector t2=Vector(b,3);
    t1=t1-t2;
    ASSERT_NEAR(2,t1.at(3),0.5f);
}
TEST(CHKSUB, case2){
    double a[4] ={1,2,3,4};
    double b[3] ={0,1,1};
    Vector t1=Vector(a,4);
    Vector t2=Vector(b,3);
    ASSERT_ANY_THROW(t1-t2);
}
TEST(CHKADD, case1){
    double a[3] ={1,2,3};
    double b[3] ={0,1,1};
    Vector t1=Vector(a,3);
    Vector t2=Vector(b,3);
    t1=t1+t2;
    ASSERT_NEAR(4,t1.at(3),0.5f);
}
TEST(CHKADD, case2){
    double a[4] ={1,2,3,4};
    double b[3] ={0,1,1};
    Vector t1=Vector(a,4);
    Vector t2=Vector(b,3);
    ASSERT_ANY_THROW(t1+t2);
}
  
TEST(CHKASSGINMENT, case1){
    double a[3] ={1,2,3};
    Vector t1=Vector(a,3);
    Vector t2;
    t2=t1;
    ASSERT_NEAR(3,t2.at(3),0.5f);
}
TEST(CHKCOPCONSTR, case1){
    double a[3] ={1,2,3};
    Vector t1=Vector(a,3);
    Vector t2=Vector(t1);
    ASSERT_NEAR(3,t2.at(3),0.5f);
}
TEST(CHALENGTH,case1){
    double a[3]={3,0,4};
    Vector t1=Vector(a,3);
    ASSERT_NEAR(5,t1.length(),0.5f);
}
TEST(CHALENGTH,case2){
    double a[3]={3,3,4};
    Vector t1=Vector(a,3);
    ASSERT_NEAR(5.83095,t1.length(),0.5f);
}


