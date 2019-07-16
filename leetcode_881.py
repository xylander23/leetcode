#!/usr/bin/env python3
# -*- coding: utf-8 -*-
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people = sorted(people, reverse=True)
        min_num = len(people) - 1
        n = 0
        i = 0
        while i<= min_num:
            place = limit - people[i]
            if place == 0:
                n += 1
            elif place >= people[min_num]:
                n += 1
                min_num -= 1
            else:
                n += 1
            i += 1
        return n