// Handel Olivier Baptiste //
#ifndef TABLEAUPLUS_H
#define TABLEAUPLUS_H

template <class  Type>
class tableauPlus
{
    public:
        tableauPlus();
         tableauPlus(int );
          tableauPlus(int , int );
         Type&  operator [](int e);
         friend   bool    operator ==(tableauPlus<Type>&,tableauPlus<Type>&);
           friend  bool   operator !=(tableauPlus<Type>&,tableauPlus<Type>&);
        Type getFin() const;
        Type getDebut() const;



    private:
         Type *Tab;
};

#endif // TABLEAUPLUS_H
