![](https://github.com/user-attachments/assets/beb02fee-f755-48b6-b565-fd09a933db43)

<div align="center" style="text-align: center;">

<h1>carrotpilot</h1>

<p>
  <b>carrotpilot is an operating system for robotics.</b>
  <br>
  Currently, it upgrades the driver assistance system in 275+ supported cars.
</p>

Quick start: `bash <(curl -fsSL smiskol.com/fork/ajouatom/carrot2-v6)`

</div>

<h1>Do not install this branch! This branch is only for testing.</h1>
We are not responsible for accidents that occur while installing and using them. We are not responsible even if the comma device is blocked.

Safety and Testing
------

* carrotpilot observes [ISO26262](https://en.wikipedia.org/wiki/ISO_26262) guidelines, see [SAFETY.md](docs/SAFETY.md) for more details.
* carrotpilot has software-in-the-loop [tests](.github/workflows/selfdrive_tests.yaml) that run on every commit.
* The code enforcing the safety model lives in panda and is written in C, see [code rigor](https://github.com/commaai/panda#code-rigor) for more details.
* panda has software-in-the-loop [safety tests](https://github.com/commaai/panda/tree/master/tests/safety).
* Internally, we have a hardware-in-the-loop Jenkins test suite that builds and unit tests the various processes.
* panda has additional hardware-in-the-loop [tests](https://github.com/commaai/panda/blob/master/Jenkinsfile).
* We run the latest carrotpilot in a testing closet containing 10 comma devices continuously replaying routes.

Licensing
------

carrotpilot is released under the MIT license. Some parts of the software are released under other licenses as specified.

Any user of this software shall indemnify and hold harmless Comma.ai, Inc. and its directors, officers, employees, agents, stockholders, affiliates, subcontractors and customers from and against all allegations, claims, actions, suits, demands, damages, liabilities, obligations, losses, settlements, judgments, costs and expenses (including without limitation attorneys’ fees and costs) which arise out of, relate to or result from any use of this software by user.

**THIS IS ALPHA QUALITY SOFTWARE FOR RESEARCH PURPOSES ONLY. THIS IS NOT A PRODUCT.
YOU ARE RESPONSIBLE FOR COMPLYING WITH LOCAL LAWS AND REGULATIONS.
NO WARRANTY EXPRESSED OR IMPLIED.**

User Data and comma Account
------

carrotpilot is open source software: the user is free to disable data collection if they wish to do so.

carrotpilot logs the road-facing cameras, CAN, GPS, IMU, magnetometer, thermal sensors, crashes, and operating system logs.
The driver-facing camera is only logged if you explicitly opt-in in settings. The microphone is not recorded.

By using carrotpilot, you agree to [our Privacy Policy](https://comma.ai/privacy). You understand that use of this software or its related services will generate certain types of user data, which may be logged and stored at the sole discretion of comma. By accepting this agreement, you grant an irrevocable, perpetual, worldwide right to comma for the use of this data.
