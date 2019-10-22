#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from collections import Counter
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        counter = Counter(S)
        record = []
        index = S[0]
        length = 0
        candicate = {}
        for i in S:
            counter[i] = counter[i] - 1
            length += 1
            candicate[i] = counter[i]
            if any(candicate.values()) is False:
                record.append(length)
                length = 0
                candicate = {}
        return record
