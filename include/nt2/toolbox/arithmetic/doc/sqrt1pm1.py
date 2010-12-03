{ 'arity': 1,
  'dptch': ['real_', 'arithmetic_'],
  'incld': [],
  'norst': False,
  'notes': [],
  'rnges': { 'real_': [['T(-10)', 'T(10)']],
             'signed_int_': [['-100', '100']],
             'unsigned_int_': [['0', '100']]},
  'rturn': { 'default': 'typename boost::result_of<nt2::meta::floating(T)>::type'},
  'specv': { 'default': { },
             'real_': { 'nt2::Inf<T>()': 'nt2::Inf<r_t>()',
                        'nt2::Minf<T>()': 'nt2::Nan<r_t>()',
                        'nt2::Mone<T>()': 'nt2::Mone<r_t>()',
                        'nt2::Nan<T>()': 'nt2::Nan<r_t>()',
                        'nt2::One<T>()': ['nt2::Sqrt_2<r_t>()-nt2::One<r_t>()','1'],
                        'nt2::Zero<T>()': 'nt2::Zero<r_t>()'},
             'signed_int_': { 'nt2::Mone<T>()': 'nt2::Mone<r_t>()',
                              'nt2::One<T>()':  ['nt2::Sqrt_2<r_t>()-nt2::One<r_t>()','1'],
                              'nt2::Zero<T>()': 'nt2::Zero<r_t>()'},
             'unsigned_int_': { 'nt2::One<T>()':  ['nt2::Sqrt_2<r_t>()-nt2::One<r_t>()','1'],
                                'nt2::Zero<T>()': 'nt2::Zero<r_t>()'}},
  'stamp': 'modified by jt the 01/12/2010',
  'tcall': None,
  'types': ['real_', 'unsigned_int_', 'signed_int_'],
  'versn': "0.0"}
