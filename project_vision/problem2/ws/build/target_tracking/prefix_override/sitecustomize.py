import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/pa8/Downloads/project_vision/problem2/ws/install/target_tracking'
