	#pragma pack(4)  
class CBase2  
{  
private:  
    char c;  
    short sh;  
    int a;  
public:  
    virtual void fOut(){ cout << "virtual 1" << endl; }  
};  
class cDerive :public CBase  
{  
private :  
    int n;  
public:  
    virtual void fPut(){ cout << "virtual 2"; }  
};
