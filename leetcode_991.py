class Solution(object):
    def brokenCalc(self, X, Y):
        """
        :type X: int
        :type Y: int
        :rtype: int
        """
        if X >= Y:
            return X - Y
        else:
            times = 0
            while Y > X:
                if Y % 2 == 0:
                    Y /= 2
                    times += 1
                else:
                    Y += 1
                    times += 1
            return times + X - Y