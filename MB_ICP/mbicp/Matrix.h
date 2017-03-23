//matrix.h

#ifndef MATRIX_H
#define MATRIX_H

class vector;
class matrix;

typedef double(*pfun)(double t);
typedef void (*fun_group)(double t,vector& y);
typedef double(*pfun2)(double t,double x);
typedef double(*pfun_arg)(double t,vector& x);
typedef void (*vector_map)(double t,vector& x,vector& y);
typedef double (*pFUN)(vector& x);
typedef void (*Fun_group)(vector& x,vector& y);
enum POSITION_STS{LT,RT,LB,RB};

_declspec(dllexport) double Gauss(pfun pf,double a,double b,int n=1);
_declspec(dllexport) double Gauss(pfun2 pf,double a,double b,double x,int n=1);
_declspec(dllexport) double Romberg(pfun pf,double a,double b,double error=1E-10);
_declspec(dllexport) double Romberg(pfun2 pf,double a,double b,double x,double error=1E-10);
_declspec(dllexport) double RK(pfun2 pf,double t0,double x0,double T,double error);
_declspec(dllexport) double Deriv1(pfun pf,double x);
_declspec(dllexport) double Deriv2(pfun pf,double x);
_declspec(dllexport) double ZeroPoint(pfun pf,double x0,double error);
_declspec(dllexport) double MinPoint1(pfun pf,double x0,double error=1E-6);
_declspec(dllexport) double MinPoint2(pfun pf,double x0,double error=1E-10);
_declspec(dllexport) void   FFT(vector& Real,vector& Imag,vector& real,vector& imag,int what);
_declspec(dllexport) void   FFT(vector& Real,vector& real,vector& imag);
_declspec(dllexport) double Mult(vector& x,matrix& A,vector& y);
_declspec(dllexport) void Plot(vector& t,vector& x);
_declspec(dllexport) void Plot(pfun pf,double a,double b,int n=100);
_declspec(dllexport) void Plot(pfun pf1,pfun pf2,double a,double b,int n=100);
_declspec(dllexport) void Plot(pfun pf1,pfun pf2,pfun pf3,double a,double b,int n=100);
_declspec(dllexport) double ED(vector& x,vector& y);

class matrix
{ 	 
 public:	 
	 friend class vector;
	 friend double Mult(vector& x,matrix& A,vector& y);
	 friend void Plot(pfun pf,double a,double b,int n);
	 friend void Plot(pfun pf1,pfun pf2,double a,double b,int n);
	 friend void Plot(pfun pf1,pfun pf2,pfun pf3,double a,double b,int n);
	 _declspec(dllexport) matrix();
	 _declspec(dllexport) matrix(int m0,int n0);	 
	 _declspec(dllexport) matrix(const matrix &ob);	 	 
	 _declspec(dllexport) ~matrix();
	 _declspec(dllexport) void Set(int m0,int n0);
	 _declspec(dllexport) void Destroy(void);
	 _declspec(dllexport) int LineSize(void); 
	 _declspec(dllexport) int ColumSize(void);	 
	 _declspec(dllexport) void DelLine(int k);
     _declspec(dllexport) void DelColum(int k);
	 _declspec(dllexport) void AddLine(vector& x);
	 _declspec(dllexport) void AddLine();
	 _declspec(dllexport) void AddColum(vector& x);
	 _declspec(dllexport) void AddColum();
	 _declspec(dllexport) void InsLine(int k,vector& x);
     _declspec(dllexport) void InsLine(int k);
	 _declspec(dllexport) void InsColum(int k,vector& x);	 
	 _declspec(dllexport) void InsColum(int k);	 
	 _declspec(dllexport) void SetColum(vector& x,int j); 
	 _declspec(dllexport) void SetLine(vector& x,int i); 
	 _declspec(dllexport) void LineSum(vector& x);
	 _declspec(dllexport) void ColumSum(vector& x);
	 _declspec(dllexport) void DiagPlus(double a);	 
	 _declspec(dllexport) void DiagPlus(vector& d);
	 _declspec(dllexport) void DiagSub(vector& d);	 
	 _declspec(dllexport) void ExchangeLine(int i,int j);
	 _declspec(dllexport) void ExchangeColum(int i,int j);
	 _declspec(dllexport) void LineTimes(int k,double landa);
	 _declspec(dllexport) void ColumTimes(int k,double landa);
	 _declspec(dllexport) void LineTimesPlus(int i,double landa,int j);
	 _declspec(dllexport) void ColumTimesPlus(int i,double landa,int j);
	 _declspec(dllexport) void TimesPlus(matrix& ob,double landa);
	 _declspec(dllexport) void GetBlock(matrix &A,int p,int q,int *u,int *v);
 	 _declspec(dllexport) void GetBlock(matrix &A,int lnum,int cnum,POSITION_STS where);	  
	 _declspec(dllexport) void GetLineBlock(matrix& A,int top,int bottom);
	 _declspec(dllexport) void GetColumBlock(matrix& A,int left,int right);
	 _declspec(dllexport) void FillIn(matrix &A,POSITION_STS where);     
	 _declspec(dllexport) void FillIn(matrix &A,int left,int top);     
 	 _declspec(dllexport) void RightLink(matrix &A,matrix &B);
	 _declspec(dllexport) void RightLink(matrix &B);
	 _declspec(dllexport) void DownLink(matrix &B);
	 _declspec(dllexport) void DownLink(matrix &A,matrix &B);	 
	 _declspec(dllexport) double AbsMax(int &r,int &s);
	 _declspec(dllexport) double AbsMax();
	 _declspec(dllexport) double AbsMin(int &r,int &s);
	 _declspec(dllexport) double AbsMin();
	 _declspec(dllexport) double Max(int &r,int &s);
	 _declspec(dllexport) double Max();
	 _declspec(dllexport) double Min(int &r,int &s);
	 _declspec(dllexport) double Min();
	 _declspec(dllexport) double Mean();
	 _declspec(dllexport) void CoVar(matrix& B);//B=((x1-mu)*(x1-mu)'+...+(xn-um)*(xn-mu)')/n
	 _declspec(dllexport) double Trace(void);
	 _declspec(dllexport) void Unit();
	 _declspec(dllexport) void Zero();
	 _declspec(dllexport) void Negative();
	 _declspec(dllexport) void DelError(double error);
	 _declspec(dllexport) void Unit(int n);
	 _declspec(dllexport) void Init(double first,...);	 
	 _declspec(dllexport) void Random(double a=0,double b=1);
	 _declspec(dllexport)void RandomGauss(vector& mu,matrix& sigama);
	 _declspec(dllexport) void RandomInt(int scope);
	 _declspec(dllexport) matrix& Plus(matrix &A,matrix &B,bool FirstTurn=0,bool SecondTurn=0);
	 _declspec(dllexport) matrix& Sub(matrix &A,matrix &B,bool FirstTurn=0,bool SecondTurn=0);     
     _declspec(dllexport) matrix& Mult(matrix &A,matrix &B,bool FirstTurn=0,bool SecondTurn=0);//////need modify
	 _declspec(dllexport) matrix& Mult(matrix &A,double landa,bool Turn=0);
	 _declspec(dllexport) matrix& Mult(vector& x,vector& y);	 	 
	 _declspec(dllexport) matrix& Turn(void);
	 _declspec(dllexport) matrix& Turn(matrix &ob);	 
	 _declspec(dllexport) void MatrixPoly(vector& p,matrix& A,bool duicheng=0);	 
	 _declspec(dllexport) double Det();	 	 
	 _declspec(dllexport) int Rank(void);
	 _declspec(dllexport) int Rang(matrix& B);
	 _declspec(dllexport) int Null(matrix& N);
	 _declspec(dllexport) bool Invers(matrix &A);	 
	 _declspec(dllexport) void PInvers(matrix& A);
	 _declspec(dllexport) bool Cholesky1(matrix& L,vector& d);
	 _declspec(dllexport) void Cholesky2(matrix& L,vector& d);
	 _declspec(dllexport) void QR(matrix &Q,matrix &R);//A=QR	 
	 _declspec(dllexport) void Eig(vector& real,vector& imag);	 
	 _declspec(dllexport) double Eig(double landa,vector& ksai);	 
	 _declspec(dllexport) double Eig(double a,double b,vector& real,vector& imag);
	 _declspec(dllexport) void Eig(vector& root,matrix& Q);//Q'AQ=diag(root[1]...root[n])
	 _declspec(dllexport) void Eig(vector& root);	 	 	 
	 _declspec(dllexport) int SVD(vector& singalvalue);
	 _declspec(dllexport) int SVD(matrix& U,matrix& S,matrix& V);//U'AV=S	 
	 _declspec(dllexport) double Norm1(void);	 
	 _declspec(dllexport) double NormInf(void);	
	 _declspec(dllexport) double Norm2(void);
	 _declspec(dllexport) double Cond(void);	 
	 _declspec(dllexport) void RK(matrix& A,double t0,vector& x0,double T,double error);	 
	 _declspec(dllexport) void RK(matrix& A,matrix& B,fun_group u,double t0,vector& x0,double T,double error);	 
	 _declspec(dllexport) void RK(pfun2 pf,double t0,double x0,double T,double error);
	 _declspec(dllexport) void RK(vector_map v_map,double t0,vector& x0,double T,double error);	 
	 _declspec(dllexport) void Hessain(pFUN pf,vector& x);	 	 
	 _declspec(dllexport) void Jacobi(Fun_group fj,int mm,vector& x);
	 _declspec(dllexport) void Exp(matrix& A,double t);
	 _declspec(dllexport) void Save(char *pathname);
	 _declspec(dllexport) void Read(char *pathname);	 
	 _declspec(dllexport) void Print(int byte=6);
	 _declspec(dllexport) void Plot();
	 _declspec(dllexport) void SplineBuild(vector& x0,vector& y0);	 
	 _declspec(dllexport) double SplineValue(double x);
	 _declspec(dllexport) void SplineValue(vector& xx,vector& yy);
	 _declspec(dllexport) double SplineDeriv(double x);
	 _declspec(dllexport) void SplineDeriv(vector& xx,vector& yy);
	 _declspec(dllexport) double SplineIntegral(double x);
	 _declspec(dllexport) double& operator()(int i,int j);	 
	 _declspec(dllexport) matrix& operator=(matrix& ob);	 	
	 _declspec(dllexport) matrix& operator+=(matrix &ob);	 
	 _declspec(dllexport) matrix& operator-=(matrix &ob);	 
	 _declspec(dllexport) matrix& operator+=(double a);	 
	 _declspec(dllexport) matrix& operator*=(matrix &ob);
  	 _declspec(dllexport) matrix& operator*=(double a);
	 _declspec(dllexport) matrix& operator/=(double a);
	 _declspec(dllexport) void    operator>>(vector& x); 
	 _declspec(dllexport) void    operator>>(double *p);
 	 _declspec(dllexport) void    operator<<(double *p);
     _declspec(dllexport) matrix  operator*(matrix& ob); 	 
	 _declspec(dllexport) matrix  operator+(matrix& ob);
	 _declspec(dllexport) matrix  operator-(matrix& ob);
	 _declspec(dllexport) vector  operator*(vector& ob); 	  	 
 private:
	 int m,n;
	 double* *start;  	 
 private:	 
	 void Hessenberg(matrix& Q);	
	 void Hessenberg(void);         
     void DoubleMove();             
	 void TQR(matrix& Q,int N,int tline);      	                        
	 void TQR(); 	                           	                           	 
	 void SvdStep1(matrix& P,matrix& Q); 
	 void SvdStep1();	   
	 void SvdStep2(matrix& P,matrix& Q,int pos,int p,int q); 	 
	 void SvdStep2();
	 int svd(matrix& U,matrix& S,matrix& V);
     int svd(vector& singalvalue); 
	 int rank(int* del_set=0);	 	 
	 void Hermit(vector& x,vector& y,vector& dy);	 
};

class vector
{ 
 public:	 
	 friend class matrix;	 
	 friend double Mult(vector& x,matrix& A,vector& y);
	 friend double ED(vector& x,vector& y);
	 friend void FFT(vector& Real,vector& Imag,vector& real,vector& imag,int what);
	 friend void FFT(vector& Real,vector& real,vector& imag);
     _declspec(dllexport) vector();
	 _declspec(dllexport) vector(int n0);	 
	 _declspec(dllexport) ~vector();	 
	 _declspec(dllexport) vector(const vector &ob);
	 _declspec(dllexport) void Set(int n0);
	 _declspec(dllexport) void Destroy();
	 _declspec(dllexport) void Zero();
	 _declspec(dllexport) void DelError(double error);
	 _declspec(dllexport) void Unit(int m,int pos);
	 _declspec(dllexport) void Init(double first,...);
	 _declspec(dllexport) void Const(double a);
	 _declspec(dllexport) void Cut(double a,double b,int m);
	 _declspec(dllexport) void Cal(pfun pf,vector& t);
	 _declspec(dllexport) void Random(double a=0,double b=1);	 
	 _declspec(dllexport) void RandomGauss(double mu=0,double xigama=1);
	 _declspec(dllexport) void RandomGamma(double aphe,double landa);
	 _declspec(dllexport) void RandomBeta(double aphe,double beta);	 
	 _declspec(dllexport) void Frequency(vector& ob);
	 _declspec(dllexport) void RandomInt(int scope);
	 _declspec(dllexport) int Size();
	 _declspec(dllexport) double& operator[](int i);	
	 _declspec(dllexport) void    operator>>(double *p);
 	 _declspec(dllexport) void    operator<<(double *p); 
	 _declspec(dllexport) vector& operator=(vector &ob);	
	 _declspec(dllexport) vector& operator+=(vector &ob);
	 _declspec(dllexport) vector  operator+(vector &ob);
	 _declspec(dllexport) vector& operator-=(vector &ob);
	 _declspec(dllexport) vector  operator-(vector &ob);
	 _declspec(dllexport) vector& operator+=(double a);
	 _declspec(dllexport) vector& operator-=(double a);	 
	 _declspec(dllexport) vector  operator*(double a);
	 _declspec(dllexport) vector& operator*=(double a);
	 _declspec(dllexport) vector& operator/=(double a);
     _declspec(dllexport) vector  operator*(matrix& ob);
	 _declspec(dllexport) double  operator*(vector& ob); 	 
	 _declspec(dllexport) void    operator>>(matrix& A);
	 _declspec(dllexport) void    operator>>(int m);
	 _declspec(dllexport) void    operator<<(int m);
	 _declspec(dllexport) double Length();
	 _declspec(dllexport) void Com(int m);
	 _declspec(dllexport) double Mean();
	 _declspec(dllexport) double Var();	 
	 _declspec(dllexport) void Invers();
	 _declspec(dllexport) vector& Link(vector& x,vector& y);
	 _declspec(dllexport) vector& Link(vector& ob);
	 _declspec(dllexport) vector& GetLeft(vector& ob,int length);
	 _declspec(dllexport) vector& GetRight(vector& ob,int length);
	 _declspec(dllexport) vector& GetMid(vector& ob,int pos,int length);
	 _declspec(dllexport) void FillIn(vector& y,int pos);
	 _declspec(dllexport) vector& Plus(vector& x,vector& y);
	 _declspec(dllexport) vector& Plus(vector& x,double a);
	 _declspec(dllexport) vector& TimesPlus(vector& ob,double t);
	 _declspec(dllexport) vector& Sub(vector& x,vector& y);
	 _declspec(dllexport) vector& Mult(vector& x,matrix& A);	 
	 _declspec(dllexport) vector& Mult(matrix& A,vector& x);	 	 
	 _declspec(dllexport) vector& Mult(vector& x,double a);	 
	 _declspec(dllexport) vector& GetLine(matrix& ob,int i);
	 _declspec(dllexport) vector& GetColum(matrix& ob,int j);	 
	 _declspec(dllexport) vector& GetDiag(matrix& ob);
	 _declspec(dllexport) void    SetDiag(matrix& ob);
	 _declspec(dllexport) double AbsMax(int &pos);
	 _declspec(dllexport) double AbsMax();
	 _declspec(dllexport) double AbsMin(int &pos);
	 _declspec(dllexport) double AbsMin();
	 _declspec(dllexport) double Max(int &pos);
	 _declspec(dllexport) double Max();
	 _declspec(dllexport) double Min(int &pos);
	 _declspec(dllexport) double Min();
	 _declspec(dllexport) vector& Add(double a);
	 _declspec(dllexport) vector& Del(int pos);
	 _declspec(dllexport) vector& Ins(double a,int pos);	 
	 _declspec(dllexport) void SmallToBig();
	 _declspec(dllexport) void BigToSmall();
	 _declspec(dllexport) int Local(double x);
	 _declspec(dllexport) double PolyValue(double landa);
	 _declspec(dllexport) void PolyDeriv(vector& x);
	 _declspec(dllexport) void PolyIntegral(vector& x);
	 _declspec(dllexport) void PolyPlus(vector& p1,vector& p2);
	 _declspec(dllexport) void PolySub(vector& p1,vector& p2);
	 _declspec(dllexport) void PolyMult(vector& p1,vector& p2);	 
	 _declspec(dllexport) void PolyDiv(vector& x,vector& y,vector& r);
	 _declspec(dllexport) void HPoly(int n);
	 _declspec(dllexport) void LPoly(int n);
	 _declspec(dllexport) void T1Poly(int n);
	 _declspec(dllexport) void T2Poly(int n);
	 _declspec(dllexport) void PolyRoot(vector& real,vector& imag);
	 _declspec(dllexport) void PolyCoef(vector& real);
	 _declspec(dllexport) void PolyCoef(vector& real,vector& imag);
	 _declspec(dllexport) void PolyMaxMin(double a,double b,double& x_max,double& x_min);
	 _declspec(dllexport) void Save(char *pathname);
	 _declspec(dllexport) void Read(char *pathname);	 
	 _declspec(dllexport) void Print(int byte=6);	 
	 _declspec(dllexport) double LE(matrix& A,vector& b);
	 _declspec(dllexport) double PLE(matrix& A,vector& b);
	 _declspec(dllexport) void ThreeDiag(vector& a,vector& b,vector& c,vector& d);
	 _declspec(dllexport) bool SqrtRoot(matrix& A,vector& b);	
	 _declspec(dllexport) void Gauss(matrix& A,vector& b);
	 _declspec(dllexport) void GaussSeidel(matrix& A,vector& b);
	 _declspec(dllexport) int LP(matrix& A,vector& b,vector& C);	 
	 _declspec(dllexport) void Grad(pFUN pf,vector& x);
	 _declspec(dllexport) double DFP(pFUN pf,double stop_error=1E-5);
	 _declspec(dllexport) double BFGS(pFUN pf,double stop_error=1E-5);
	 _declspec(dllexport) double FR(pFUN pf,double stop_error=1E-10);
	 _declspec(dllexport) double Powell(pFUN pf,double stop_error=1E-14);
	 _declspec(dllexport) double Newton(pFUN pf,double stop_error=1E-5);
	 _declspec(dllexport) double Hook(pFUN pf,double stop_error=1E-14);
	 _declspec(dllexport) double Rosen(pFUN pf,double stop_error=1E-10);
	 _declspec(dllexport) double Simplex(pFUN pf,double stop_error=1E-14);
	 _declspec(dllexport) double TR(pFUN pf,double stop_error=1E-5);
	 _declspec(dllexport) double LMF(Fun_group rj,int rnum,double stop_error=1E-8);	 	 
	 _declspec(dllexport) double Lagrange(pFUN pObj,Fun_group g_group,int g_num,Fun_group h_group,int h_num,double punish=10);
	 _declspec(dllexport) double Lagrange1(pFUN pObj,Fun_group g_group,int g_num,double punish=10);
	 _declspec(dllexport) double Lagrange2(pFUN pObj,Fun_group h_group,int h_num,double punish=10);
	 _declspec(dllexport) double SQP(pFUN pObj,Fun_group g_group,int g_num,Fun_group h_group,int h_num);
	 _declspec(dllexport) double SQP1(pFUN pObj,Fun_group g_group,int g_num);
	 _declspec(dllexport) double SQP2(pFUN pObj,Fun_group h_group,int h_num);
	 _declspec(dllexport) double Gauss(pfun_arg pf,double a,double b,int n=1);	 
 	 _declspec(dllexport) double Romberg(pfun_arg pf,double a,double b,double error=1E-10);     	 	 
	 _declspec(dllexport) void RK(vector_map v_map,double t0,vector& x0,double T,double error);	 
	 _declspec(dllexport) void RK(matrix& A,double t0,vector& x0,double T,double error);	 	 
	 _declspec(dllexport) void RK(matrix& A,matrix& B,fun_group u,double t0,vector& x0,double T,double error);	 
	 _declspec(dllexport) void QLB(pfun pf,pfun qf,pfun rf,double a,double b,double y_a,double y_b,int N);	 
	 _declspec(dllexport) void SplineValue(matrix& A,vector& x);	 
     _declspec(dllexport) void SplineDeriv(matrix& A,vector& x);	 	 	 
	 _declspec(dllexport) double PolyOUA(pfun pf,int n); 
	 _declspec(dllexport) double PolyLSA(pfun pf,int n); 
	 _declspec(dllexport) double PolyFit(vector& x,vector& y,int n);
	 _declspec(dllexport) void LConvolute(vector& x,vector& y);	 
	 
 private:
	 int n;
	 double* head;	 
 private:	 	 
	 double d3p2find(pFUN pf,vector& x);	 	 	
     double goldfind(pFUN pf,vector& x);	 	 
	 void DelZero();	 
	 bool LPInitPoint(matrix& A,vector& b);	
	 bool QPInitPoint(matrix& A,vector& a,matrix& E,vector& e);
	 bool QPInitPoint(matrix& A,vector& a);	 
	 bool QP(matrix& G,vector& g,matrix& A,vector& a,matrix& E,vector& e,vector& Landa,vector& Mu);
	 bool QP1(matrix& G,vector& g,matrix& A,vector& a,vector& Mu);
	 bool QP2(matrix& G,vector& g,matrix& E,vector& e,vector& Landa);	 
	 bool CurvatureDirection(matrix& H,matrix& L,vector& d);
	 bool CheckRound(pFUN pf,vector& x);
	 void detectI(pFUN pf,vector& begin,vector& end,double step);	 
	 void turn_direction(matrix& P,vector& d);	 	 
	 void RK(vector_map v_map,double t0,double T,double error);	 
	 void RK(matrix& A,double t0,double T,double error);	 	 
	 void RK(matrix& A,matrix& B,fun_group u,double t0,double T,double error);
	 void QLB(pfun pf,pfun qf,pfun rf,double a,double b,double y_a,double y_b);	 	 
	 double PolyLSA(pfun pf); 
	 double PolyOUA(pfun pf); 
	 double PolyFit(vector& x0,vector& y0);	 
	 static double Romberg_xn(pfun pf,int degree,double error=1E-10);	 
	 static double Romberg_qrt(pfun pf,double error=1E-10);	 
	 static double Chbixif(pfun pf,int k,double error=1E-10);	 	 
	 static double Gamma(double aphe);	 
	 void RK_SUBPRO(vector_map v_map,double t_cur,vector& x_cur,double h_cur,double error,double& t_next);	 
	 void RK_SUBPRO(matrix& A,double t_cur,vector& x_cur,double h_cur,double error,double& t_next);	 
	 void RK_SUBPRO(matrix& A,matrix& B,fun_group u,double t_cur,vector& x_cur,double h_cur,double error,double& t_next);
};
#endif