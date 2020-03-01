#!/usr/bin/env python3
# -*- coding: utf-8 -*-
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        sub_str = []
        max_str = 0
        for ele in s:
            if ele not in sub_str:  #  如果没有在列表中那么就添加
                sub_str.append(ele)
            else:
                length = len(sub_str)  # 先记录之前最长的子串
                if length > max_str:
                    max_str = len(sub_str)
                if length == 1:  # 如果连续两个一样就不必再定位相同的字
                    continue
                index = sub_str.index(ele)
                sub_str.append(ele)
                sub_str = sub_str[index+1:]
        max_str = len(sub_str) if len(sub_str) > max_str else max_str
        return max_str
