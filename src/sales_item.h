/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 *     Pearson Education, Inc.
 *     Rights and Permissions Department
 *     One Lake Street
 *     Upper Saddle River, NJ  07458
 *     Fax: (201) 236-3290
 */

/* This file defines the SaleItem class used in chapter 1.
 * The code used in this file will be explained in
 * Chapter 7 (Classes) and Chapter 14 (Overloaded Operators)
 * Readers shouldn't try to understand the code in this file
 * until they have read those chapters.
 */

#ifndef SALESITEM_H
// we're here only if SALESITEM_H has not yet been defined
#define SALESITEM_H

// Definition of SaleItem class and related functions goes here
#include <iostream>
#include <string>

class SaleItem {
  // these declarations are explained section 7.2.1, p. 270
  // and in chapter 14, pages 557, 558, 561
  friend std::istream& operator>>(std::istream&, SaleItem&);
  friend std::ostream& operator<<(std::ostream&, const SaleItem&);
  friend bool operator<(const SaleItem&, const SaleItem&);
  friend bool operator==(const SaleItem&, const SaleItem&);

 public:
  // constructors are explained in section 7.1.4, pages 262 - 265
  // default constructor needed to initialize members of built-in type
  SaleItem() : units_sold(0), revenue(0.0) {}
  SaleItem(const std::string& book)
      : bookNo(book), units_sold(0), revenue(0.0) {}
  SaleItem(std::istream& is) { is >> *this; }

 public:
  // operations on SaleItem objects
  // member binary operator: left-hand operand bound to implicit this pointer
  SaleItem& operator+=(const SaleItem&);

  // operations on SaleItem objects
  std::string isbn() const { return bookNo; }
  double avg_price() const;
  // private members as before
 private:
  std::string bookNo;  // implicitly initialized to the empty string
  unsigned units_sold;
  double revenue;
};

// used in chapter 10
inline bool compareIsbn(const SaleItem& lhs, const SaleItem& rhs) {
  return lhs.isbn() < rhs.isbn();
}

// nonmember binary operator: must declare a parameter for each operand
SaleItem operator+(const SaleItem&, const SaleItem&);

inline bool operator==(const SaleItem& lhs, const SaleItem& rhs) {
  // must be made a friend of SaleItem
  return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue &&
         lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const SaleItem& lhs, const SaleItem& rhs) {
  return !(lhs == rhs);  // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
SaleItem& SaleItem::operator+=(const SaleItem& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

// assumes that both objects refer to the same ISBN
SaleItem operator+(const SaleItem& lhs, const SaleItem& rhs) {
  SaleItem ret(lhs);  // copy (|lhs|) into a local object that we'll return
  ret += rhs;           // add in the contents of (|rhs|)
  return ret;           // return (|ret|) by value
}

std::istream& operator>>(std::istream& in, SaleItem& s) {
  double price;
  in >> s.bookNo >> s.units_sold >> price;
  // check that the inputs succeeded
  if (in)
    s.revenue = s.units_sold * price;
  else
    s = SaleItem();  // input failed: reset object to default state
  return in;
}

std::ostream& operator<<(std::ostream& out, const SaleItem& s) {
  out << s.isbn() << " " << s.units_sold << " " << s.revenue << " "
      << s.avg_price();
  return out;
}

double SaleItem::avg_price() const {
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}
#endif
