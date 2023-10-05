// Handel Olivier Baptiste //

class rectangle
{
public:
rectangle();
rectangle(double,double);
void setDimension(double , double );
rectangle( const rectangle&);
double getLong() const ;
double getLarg() const;
double getSurface() const;
double getPerimetre() const ;
rectangle operator  +(rectangle&) ;
friend bool operator ==(rectangle&,rectangle&);
friend bool operator != (rectangle&,rectangle&);
rectangle& operator ++ ();
rectangle& operator ++ (int );

private:
	double Longueur,largeur;

};
