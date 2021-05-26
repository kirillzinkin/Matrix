#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

#include <iostream>
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template <class ValType>
class TVector
{
protected:
  ValType* pVector;
  int Size;
  int StartIndex;
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector& v);
  ~TVector();
  int GetSize() { return Size; }
  int GetStartIndex() { return StartIndex; }
  ValType& operator[](int pos);
  bool operator==(const TVector& v) const;
  bool operator!=(const TVector& v) const;
  TVector& operator=(const TVector& v);
  TVector  operator+(const ValType& val);
  TVector  operator-(const ValType& val);
  TVector  operator*(const ValType& val);
  TVector  operator+(const TVector& v);
  TVector  operator-(const TVector& v);
  ValType  operator*(const TVector& v);
  friend std::istream& operator>>(std::istream& in, TVector& v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const TVector& v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <typename ValType>
TVector<ValType>::TVector(int s, int si)
{
  if ((s < 0) || (s >= MAX_VECTOR_SIZE)) throw "negative or too large vector size";
  if (si < 0) throw "negative or too large startindex";
  Size = s;
  StartIndex = si;
  pVector = new ValType[s];
  for (int i = 0; i < s; i++)
    pVector[i] = 0;
}

template <typename ValType>
TVector<ValType>::TVector(const TVector& v)
{
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new ValType[Size];
  for (int i = StartIndex; i < Size; i++)
    pVector[i] = v.pVector[i];
}

template<typename ValType>
TVector<ValType>::~TVector()
{
  delete[] pVector;
}

template<typename ValType>
ValType& TVector<ValType>::operator[](int pos)
{
  if ((pos < StartIndex) || (pos >= Size))
    throw "Wrong position";
  return pVector[pos];
}

template <typename ValType>
bool TVector<ValType>::operator==(const TVector& v) const
{
  bool res = true;
  if (this == &v)
    return res;
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    res = false;
  else for (int i = StartIndex; i < Size; i++)
    if (pVector[i] != v.pVector[i]) 
    {
      res = false;
      break;
    }
  return res;
}

template <typename ValType>
bool TVector<ValType>::operator!=(const TVector& v) const
{
  bool res = false;
  if (this == &v) return res;
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    res = true;
  else for (int i = StartIndex; i < Size; i++)
    if (pVector[i] != v.pVector[i]) 
    {
      res = true;
      break;
    }
  return res;
}

template <typename ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
  if (this != &v)
  {
    if (Size != v.Size)
    {
       Size = v.Size;
       delete[] pVector;
       pVector = new ValType[Size];
    }
     StartIndex = v.StartIndex;
     for (int i = 0; i < Size; i++)
       pVector[i] = v.pVector[i];
  }
  return *this;
}

template <typename ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
  TVector sum(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    sum.pVector[i] = pVector[i] + val;
  return sum;
}

template <typename ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
  TVector sum(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    sum.pVector[i] = pVector[i] - val;
  return sum;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
  TVector comp(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    comp.pVector[i] = pVector[i] * val;
  return comp;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector& v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    throw "Wrong size";
  TVector sum(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    sum.pVector[i] = pVector[i] + v.pVector[i];
  return sum;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector& v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    throw "Wrong size";
  TVector sum(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    sum.pVector[i] = pVector[i] - v.pVector[i];
  return sum;
}

template<typename ValType>
ValType TVector<ValType>::operator*(const TVector& v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    throw "Wrong size";
  ValType comp = 0;
  for (int i = StartIndex; i < Size; i++)
    comp += pVector[i] * v.pVector[i];
  return comp;
}
#endif
