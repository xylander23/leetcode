#!/usr/bin/env python3
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        if len(hand) % W != 0:
            return False
        else:
            time = int(len(hand) / W)
            hand = sorted(hand)
            for i in range(time):
                small = hand[0]
                hand.pop(0)
                for j in range(W-1):
                    candicate = small+j+1
                    if candicate in hand:
                        hand.remove(candicate)
                    else:
                        return False
            return True