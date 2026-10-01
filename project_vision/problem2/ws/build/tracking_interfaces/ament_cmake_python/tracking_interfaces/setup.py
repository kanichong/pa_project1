from setuptools import find_packages
from setuptools import setup

setup(
  name='tracking_interfaces',
  version='0.1.0',
  packages=find_packages(
      include=('tracking_interfaces', 'tracking_interfaces.*')),
)
