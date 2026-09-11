// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

 //конструктор с параметром - максимальной длиной битового поля (BitLen)
TBitField::TBitField(int len) : BitLen(len)
{
    if (len < 0) {
        throw "Negative number of bytes. Try another one";
    }
    MemLen = (len + (sizeof(TELEM) * 8) - 1) / (sizeof(TELEM) * 8);
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

// конструктор копирования
TBitField::TBitField(const TBitField &bf)
{
}

//деструктор, должен лишь освободить динамическую память
TBitField::~TBitField()
{
    delete[] pMem;
}

// индекс Мем для бита n (индекс блока-элемента TELEM в массиве pMem)
int TBitField::GetMemIndex(const int n) const
{
    if (n < 0 || n >= BitLen) {
        throw "Index is out of range. Try another one";
    }
    return (n / (sizeof(TELEM) * 8));
}

// битовая маска для бита n
TELEM TBitField::GetMemMask(const int n) const
{
    if (n < 0 || n >= BitLen) {
        throw "Index is out of range. Try another one";
    }
    TELEM mask = (TELEM)1 << (n % (sizeof(TELEM) * 8));
    return mask;
}

// доступ к битам битового поля

// получить длину (к-во битов)
int TBitField::GetLength(void) const
{
  return BitLen;
}

// установить бит
void TBitField::SetBit(const int n)
{
    if (n < 0 || n >= BitLen) {
        throw "Index is out of range. Try another one";
    }
    int MemIndex = GetMemIndex(n);
    TELEM MemMask = GetMemMask(n);
    pMem[MemIndex] = pMem[MemIndex] | MemMask; 
}

// очистить бит
void TBitField::ClrBit(const int n)
{
    if (n < 0 || n >= BitLen) {
        throw "Index is out of range. Try another one";
    }
    int MemIndex = GetMemIndex(n);
    TELEM MemMask = GetMemMask(n);
    pMem[MemIndex] = pMem[MemIndex] & ~MemMask;
}

// получить значение бита
int TBitField::GetBit(const int n) const
{
    if (n < 0 || n >= BitLen) {
        throw "Index is out of range. Try another one";
    }
    int MemIndex = GetMemIndex(n);
    TELEM MemMask = GetMemMask(n);
    TELEM temp = pMem[MemIndex];
    temp = temp & MemMask;
    temp = temp >> (n % (sizeof(TELEM) * 8));
    return temp;
}

// битовые операции

// присваивание
TBitField& TBitField::operator=(const TBitField &bf)
{
    return *this;
}

// сравнение
int TBitField::operator==(const TBitField &bf) const 
{
  return 0;
}

// сравнение
int TBitField::operator!=(const TBitField &bf) const
{
  return 0;
}

// операция "или"
TBitField TBitField::operator|(const TBitField &bf)
{
    return TBitField(0);
}

// операция "и"
TBitField TBitField::operator&(const TBitField &bf)
{
    return TBitField(0);
}

// отрицание
TBitField TBitField::operator~(void)
{
    return TBitField(0);
}

// ввод/вывод

// ввод
std::istream &operator>>(std::istream &istr, TBitField &bf)
{
    return istr;
}

// вывод
std::ostream &operator<<(std::ostream &ostr, const TBitField &bf)
{
    return ostr;
}
