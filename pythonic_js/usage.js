
require("./pythonic")

// vars casting
i = int("12")
s = str(12)
print(i)
print(s)

// strings methods
print( len("my string") )
print( "my string".upper() )
print( "my string".startswith("my") )
print( " my string ".strip() )
print( "my string".find("y") )
print( "my string".split(" "))  // already supported

// list-like methods
l = [ 1, 2, 3 ]
print( list("my string") )
print( len(l) )
//l.find(2)  // already supported
print( l.count(2) )
print( l.append(4) )
print( l.extend([5, 6]) )
l.remove(6); print( l )
print( l.pop(1) )
print( l.sort() )
print( l.reverse() )
print( l2 = l.copy() )

// dict-like methods
d = {"a": 1, "b": 2}
print( len(d) )
print( d.keys() )
print( d.values() )
d2 = d.copy()
print( d2 )

// global functions
print( dir(d) )
print( range(10) )
print( range(10, 20) )
print( abs(-1) )
print( round(0.5) )

// stdlib modules
d = json.loads("{\"1\":2}")
print( d )
print( math.cos(10) )

