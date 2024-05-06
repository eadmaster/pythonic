

/* MEMO USAGE:
require("./python")

// vars casting
    i = int("12")
    s = str(12)

// strings methods
    len("my string")
    "my string".upper()
    "my string".startswith("my")
    " my string ".strip()
    "my string".find("y")
    "my string".split(" ")  // already supported
    
// list-like methods
    l = [ 1, 2, 3 ]
    list("my string")
    len(l)
    l.find(2)  // already supported
    l.count(2)
    l.append(4)
    l.extend([5, 6])
    l.remove(6)
    l.pop(1)
    l.sort()
    l.reverse()
    l2 = l.copy()

// dict-like methods
    d = {"a": 1, "b": 2}
    len(d)
    d.keys()
    d.values()
    d2 = d.copy()

// global functions
    dir(o)
    range(10)
    range(10, 20)
    abs(-1)
    round(0.5)

// famous modules
    d = json.loads("{\"1\":2}")
    math.cos(10)
    
 
*/

// constants
None = null
True = true
False = false

// TODO: alias function -> def  https://stackoverflow.com/questions/35924399/javascript-alias-for-function-keyword
// TODO: alias delete -> del
// TODO: alias in -> ...
// TODO: alias is -> Object.is()?
// TODO: alias && -> and
// TODO: alias || -> or
// TODO: alias ! -> not

// stdlib methods aliases
String.prototype.upper = String.prototype.toUpperCase
String.prototype.lower = String.prototype.toLowerCase
String.prototype.startswith = String.prototype.startsWith
String.prototype.endswith = String.prototype.endsWith
String.prototype.splitlines = function() { return(this.split("\n")); }
String.prototype.strip = String.prototype.trim
String.prototype.lstrip = String.prototype.trimLeft
String.prototype.rstrip = String.prototype.trimRight
String.prototype.find = String.prototype.search
String.prototype.join = function(l) { return(l.join(this)); }

Object.prototype.keys = function() { return(Object.keys(this)); }
Object.prototype.values = function() { return(Object.values(this)); }
Object.prototype.copy = function() { return(JSON.parse(JSON.stringify(this))); }  // source: https://stackoverflow.com/questions/7486085/copy-array-by-value
Object.prototype.dir = function(o) { return(Object.getOwnPropertyNames(o.__proto__)); }

// global function aliases
global.print = console.log
global.printf = console.log
global.len = function(o) { if(typeof o === "object") { return(Object.keys(o).length) } else { return(o.length); } }  // TODO: check o.size for sets and more?
global.isinstance = function(o, c) { return(o instanceof c); }  // # isinstance equivalent
global.type = function(o) { if(Array.isArray(o)) { return('list') } else { return(typeof o); } }  // TODO: return the actual class object instead of a string?
//NO(native types only)? global.str = function(o) { return(o.toString()); }
//global.getattr = function(object, name, default=null) { ...
//global.setattr = function(object, name, value) { ...
global.str = JSON.stringify
global.bool = Boolean;
global.int = function(o, base) { base = base || 10; r = parseInt(o, base); if(isNaN(r)) throw Error("cannot parse int from: " + JSON.stringify(o)); return(r); }  // parseInt won't thrown exceptions on errors, returns "NaN" if first char is invalid digit
global.long = int;
global.float = function(o) { r = parseFloat(o); if(isNaN(r)) throw Error("cannot parse int from: " + JSON.stringify(o)); return(r); }
global.chr = function(i) { return(String.fromCharCode(i)); }  // int->char
global.ord = function(c) { return(c.charCodeAt(0)); }   // char->int
global.hex = function(i) { return("0x"+i.toString(16)); }   // int->hex string
global.oct = function(i) { return("0"+i.toString(8)); }   // int->octal string
global.bin = function(i) { return("0b"+i.toString(2)); }   // int->binary string
global.list = function(i) { return(Array.from(i)); }
global.tuple = global.list  // there are no native tuples in js, so we use lists instead
global.set = function(i) { return(new Set(i)); }
// TODO: global.sorted
// TODO: global.dict
// TODO: global.vars 

//NO(NO STEP)? global.range = function(n) { return/Array.from(Array(n).keys())); }
global.range = function(start=0, stop, step=1) {  // source: https://stackoverflow.com/questions/8273047/javascript-function-similar-to-python-range
    if (typeof stop == 'undefined') {
        // one param defined
        stop = start;
        start = 0;
    }
    if (typeof step == 'undefined') {
        step = 1;
    }
    if ((step > 0 && start >= stop) || (step < 0 && start <= stop)) {
        return [];
    }
    var result = [];
    for (var i = start; step > 0 ? i < stop : i > stop; i += step) {
        result.push(i);
    }
    return result;
};

Array.prototype.index = function(v) { r = this.indexOf(v); if(r==-1) throw Error(v + " is not in list"); return(r); }
Array.prototype.count = function(v) { return this.reduce((prev, curr) => (prev[curr] = ++prev[curr] || 1, prev), {})[v]; }  // TODO: more efficient ver.
Array.prototype.append = function(v) { this.push(v); return this;  }
Array.prototype.extend = Array.prototype.concat
Array.prototype.insert = function ( index, item ) { this.splice( index, 0, item ); };
Array.prototype.remove = function(v) { this.splice(this.indexOf(v), 1); }  // TODO: raise exception if not found
Array.prototype.pop =  function(i=-1) { return(this.splice(i, 1)); }  // TODO: raise exception if not found
global.any = function(func, a) { return(a.some(func)); }
global.all = function(func, a) { return(a.every(func)); }
global.filter = function(func, a) { return(a.filter(func)); }
global.reduce = function(func, a) { return(a.reduce(func)); }
global.map = function(func, a) { return(a.map(func)); }
// TODO: global.enumerate = function(func, a) { return(); }

global.abs = Math.abs
global.min = Math.min
global.max = Math.max
global.pow = Math.pow
global.round = Math.round
// TODO: global.sum = ...

global.math = Math
global.math.pi = Math.PI
global.math.e = Math.E

global.re = {
	match: function(re, s) { return(s.match(re)); }, // TODO: add optional args "[, pos[, endpos]]"
	search: function(re, s) { return(s.search(re)); },
	compile: RegExp
}
RegExp.prototype.match = String.prototype.match
RegExp.prototype.search = String.prototype.search

global.datetime = {
	date: Date,
	time: Date,
	datetime: Date
	// TODO: timedelta
}
//Date.prototype.now = Date;
/* TODO: global.time = {
	time: Date
}
//TODO: Date.prototype.utcnow = 
//TODO: add as a field: Date.prototype.year = this.getFullYear()
//TODO: add as a field: Date.prototype.month = Date.prototype.getMonth
//TODO: add as a field: Date.prototype.day = Date.prototype.getDay
//TODO: add as a field: Date.prototype.hour = Date.prototype.getHours
//TODO: add as a field: Date.prototype.minute = Date.prototype.getMinutes
//TODO: add as a field: Date.prototype.second = Date.prototype.getSeconds
//TODO: add as a field: Date.prototype.today
* if(Date.prototype.toLocaleFormat) Date.prototype.strftime = Date.prototype.toLocaleFormat
* */

global.json = {
    dumps: function(v) { return(JSON.stringify(v)); },
    loads: function(v) { return(JSON.parse(v)); },
    // TODO: dump
    // TODO: load
}

global.logging = {
	debug: function(msg) { console.log(msg); },
	info: function(msg) { console.info(msg); },
	warning: function(msg) { console.warn(msg); },
	error: function(msg) { console.error(msg); }
	//critical: function(msg) {}
}

global.string = {
	ascii_lowercase: 'abcdefghijklmnopqrstuvwxyz',
	ascii_uppercase: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
	ascii_letters: this.ascii_lowercase + this.ascii_uppercase,
	digits: '0123456789',
	punctuation: '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~',
	whitespace: '\t\n\x0b\x0c\r ',
	printable: this.digits + this.ascii_letters + this.punctuation + this.whitespace
}
//TODO: String.prototype.isprintable = 
//TODO: String.prototype.isnumeric = 
/*TODO: global.hashlib { https://docs.python.org/2/library/hashlib.html
* using https://developer.mozilla.org/en-US/docs/Web/API/SubtleCrypto/digest
}*/

/*TODO: global.binascii {
* http://eadmaster.altervista.org/txt2tags-php/txt2tags.php?id=python#toc62
* https://developer.mozilla.org/en-US/docs/Web/API/WindowBase64/Base64_encoding_and_decoding
}*/
 

// detect node.js
// TODO: more reliable way
if (typeof window === 'undefined') {
    // NODEJS MODE
    console.log("python.js: running in node.js, adding more stuff");
    
    //const fs = require('fs');
    fs = require('fs')
    global.os = fs;  // incl. rename, stat, mkdir, ...
    global.os.remove = fs.unlinkSync;
    //global.open = fs.openSync; // TODO: proper file object
    //global.open = fs.promises.open;  // req. nodejs >=10

} else {
    // BROWSER MODE
    
    // requests using fetch + await https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API/Using_Fetch
    //   https://gist.github.com/msmfsd/fca50ab095b795eb39739e8c4357a808
    global.requests = {
	get: async function(url, options) {
		    var response = await fetch(url, options);
		    return await response;
	},

	post: function(url, options) {
		    options = options || {}
		    options['method']='POST'
		    return(get(url, options));
	},
	
	put: function(url, options) {
		    options = options || {}
		    options['method']='PUT'
		    return(get(url, options));
	},
	
	delete: function(url, options) {
		    options = options || {}
		    options['method']='DELETE'
		    return(get(url, options));
	}
    };
}
    
