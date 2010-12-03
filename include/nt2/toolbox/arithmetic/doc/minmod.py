{ 'arity': 2,
  'dptch': ['real_', 'unsigned_', 'arithmetic_'],
  'incld': [],
  'norst': False,
  'notes': [],
  'rnges': { 'real_': [['T(-10)', 'T(10)'], ['T(-10)', 'T(10)']],
             'signed_int_': [['-100', '100'], ['-100', '100']],
             'unsigned_int_': [['0', '100'], ['0', '100']]},
  'rturn': { 'default': 'typename boost::result_of<nt2::meta::arithmetic(T,T)>::type'},
  'specv': { 'default': { },
             'real_': { 'nt2::Inf<T>()': 'nt2::Inf<T>()',
                        'nt2::Minf<T>()': 'nt2::Minf<T>()',
                        'nt2::Mone<T>()': 'nt2::Mone<T>()',
                        'nt2::Nan<T>()': 'nt2::Nan<T>()',
                        'nt2::One<T>()': 'nt2::One<T>()',
                        'nt2::Zero<T>()': 'nt2::Zero<T>()'},
             'signed_int_': { 'nt2::Mone<T>()': 'nt2::Mone<T>()',
                              'nt2::One<T>()': 'nt2::One<T>()',
                              'nt2::Zero<T>()': 'nt2::Zero<T>()'},
             'unsigned_int_': { 'nt2::One<T>()': 'nt2::One<T>()',
                                'nt2::Zero<T>()': 'nt2::Zero<T>()'}},
  'stamp': 'modified by jt the 01/12/2010',
  'tcall': "(a0*a1>0)? nt2::min(a0,a1):0",
  'types': ['real_', 'unsigned_int_', 'signed_int_'],
  'versn': 0.0}
