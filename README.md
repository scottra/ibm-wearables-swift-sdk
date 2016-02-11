# Overview
This framework facilitates the development of iOS apps that utilize Wearable or Nearable Devices. It helps developing those apps in just a fraction of the time and requiring only minimal knowledge of the Wearable/Nearable domain.

It is especially helpful for building solutions that use the compute power of the smartphone to interpret raw data from Wearables into meaningful situations that can be acted upon.

It handles the key aspects of utilizing Wearable devices:
- Connecting to the Wearable/Nearable Devices.
- Retrieving data from a specific sensor.
- Making the data available in a standard way regardless of the sensor's make.
- Interpreting raw data and identifying meaningful situations that can be acted upon.
- Identifying Gestures (coming soon)

It is accompanied by rich documentation and sample code.

This framework follows the paradigm illustrated in the diagram below: 
The mobile device is applied as a first-line compute power for processing the huge amount of data coming from Wearable devices and turning it into insights on the user's current context and situation. You may then trigger the necessary actions or send the insightful information to the cloud for further processing and interoperasbility with other applications.

![header](https://cloud.githubusercontent.com/assets/16938963/12744518/6b4d7b82-c99d-11e5-9a1c-8867a2dc4179.png)


# Documentation
Please visit the [Wiki](https://github.com/ibm-wearables-sdk-for-mobile/ios/wiki).

# Gesture Recognition (coming soon)
The client-side components of the Gesture Recognition are open source and are available here. Learning a new gesture and generating a corresponding algorithm necessiates utilization of a cloud service that requires an activation code. The code can be freely obtained [here](http://wearables.mybluemix.net/).

***Act now to Secure your free access to the Gesture Recognition cloud service by registering at: http://wearables.mybluemix.net/*** 

# License
© Copyright 2016 IBM Corp.
  Licensed under the Mobile Edge iOS Framework License (the "License");
  you may not use this file except in compliance with the License. You may find
  a copy of the license in the license.txt file in this package.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
  