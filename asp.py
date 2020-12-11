class geeks:  
    def __init__(self, name, roll):  
        self.name = name  
        self.roll = roll 
   
# creating list        
list = []  
  
# appending instances to list  
list.append( geeks('Akash', 2) ) 
list.append( geeks('Deependra', 40) ) 
list.append( geeks('Reaper', 44) ) 
  
print( list[1].name, list[1].roll, sep =' ' ) 
print( list[0].name, list[0].roll, sep =' ' ) 
print( list[2].name, list[2].roll, sep =' ' ) 