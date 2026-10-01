from glob import glob
from setuptools import setup

package = 'target_tracking'
setup(
    name=package,
    version='0.1.0',
    packages=[package],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package]),
        ('share/' + package, ['package.xml']),
        ('share/' + package + '/launch', glob('launch/*.py')),
        ('share/' + package + '/config', glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='pa8',
    description='문제 2 인지·제어 노드 연결',
    license='Apache-2.0',
    entry_points={'console_scripts': [
        f'{n} = {package}.{n}_node:main' for n in
        ['detector', 'controller', 'motor_driver', 'input_test', 'pan_sim', 'search_test', 'interface_check']
    ]},
)
