datadir="data"
datafile="updatecppdata"

def generate_cpp_function( fun_dict):
    fun_str = '%s %s(' % (fun_dict[0]["Type"], fun_dict[0]["Name"])
    
    for parameter in fun_dict[1:]:
        fun_str +='%s %s,' % (parameter["Type"], parameter["Name"])
    fun_str = fun_str[:-1]

    fun_str += ') {\n'
    fun_str += '\n'
    if fun_dict[0]["Type"] == "void":
        fun_str += '\n';
    else:
        fun_str += '\tretrun 0;\n'
    fun_str += '}\n'


    return fun_str

#def cpp_parseout_methods(fun_str = ""):

fun_list = [[{'Type':"int", 'Name':"invert"},{'Type':"float", 'Name':"num"}],
            [{'Type':"int", 'Name':"main"}],
            [{'Type':"void", 'Name':"loop"}],
            [{'Type':"double", 'Name':"abs"},{'Type':"double", 'Name':"rela"},{'Type':"double", 'Name':"imag"}]]

for fun in fun_list:
    print( generate_cpp_function(fun))
