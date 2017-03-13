

class Calculate:

    def __init__(self, f):
        self.f = f
     
    
    def cal_avg(self, f):
    
        self.f = f

        f.seek(0)
        a = []
    
        for line in f:
            score = float(sorted(line.split(",")).pop(0))
            a.append(score)
    
        print "Average score: " 
        print sum(a)/float(len(a))

