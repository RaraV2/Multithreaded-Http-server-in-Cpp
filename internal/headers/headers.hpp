#pragma once
#include <bits/stdc++.h>
#include <cctype>
#include <string>
#include <tuple>

struct HTTP_Header {
  std::string key;
  std::string value;
};

std::tuple<HTTP_Header, size_t, bool, bool>
HTTPHeader_Parser(const std::string &rawBytes);

bool fieldNameValidator(const std::string &);
std::string trim(const std::string &);
