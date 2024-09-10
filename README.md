![FreescaleFRDM-KL46Z-big-01](https://github.com/user-attachments/assets/39a443ae-7f9d-456f-af68-ca52b817b873)<br>

- [1. Introduction](#1-introduction)
- [2. Features and Functionality](#2-features-and-functionality)
- [3. Document](#3-document)
- [4. Installation and Run](#4-installation-and-run)
- [5. Notes](#5-notes)
- [6. Authors](#6-authors)
- [7. License](#7-license)


## 1. Introduction
- The MKL46 bootloader project plays a crucial role in programming the MKL46 microcontroller via UART communication.
- Bootloader is a application used to erase flash and load user applications to a device. Bootloaders are responsible for initializing the system and loading application programs into the microcontroller’s memory. The user can update device firmware easily without using debugger
- In my project, I adhere to the CMSIS (Cortex Microcontroller Software Interface Standard) to develop a robust and maintainable bootloader.

## 2. Features and Functionality
2.1.  Loading Application Programs into the Microcontroller’s Memory:<br>
This feature involves the process of loading application programs (firmware) into the memory of the MKL46 microcontroller (Hardware). <br>
![System-Software-Vs-Application-Software](https://github.com/user-attachments/assets/b6ff3ce6-b9c8-43b0-aebd-ba36c16b541e)<br>

2.2.  Easy Firmware Updates via UART Communication without using debugger:<br>
With this functionality, I enable straightforward firmware updates without requiring a debugger. The microcontroller can receive updated firmware over the UART interface, allowing for efficient maintenance and enhancements. <br>
![frdm-kl46z-components--](https://github.com/user-attachments/assets/f64843e9-59f8-4cae-8cda-c3121127e62b)<br>

2.3. SREC File Format Verification:<br>
As part of our bootloader, I implement the ability to verify firmware files in the SREC (S-Record) format. SREC is a common file format used for representing binary data, including firmware images. Ensuring the integrity of these files is essential for reliable system operation.<br>
![Motorola_SREC_Chart](https://github.com/user-attachments/assets/1461fe90-ea0f-429b-928c-dda2c0ca3723)<br>


## 3. Document
 - KL46P121M48SF4RM - Kinetis<br>
 - FRDM-KL46Z User's Manual<br>
 - Cortex™ - M0+ Devices - Generic User Guide

## 4. Installation and Run
4.1 Install Kinetis Design Studio (KDS):<br>
First, download and install KDS, which is an integrated development environment (IDE) for Kinetis microcontrollers. You can find KDS on the NXP website or other reliable sources.<br>
![images](https://github.com/user-attachments/assets/4e13dc36-378e-42ef-ba51-8e18bb134585)<br>

4.2 Flash Your Bootloader onto the KL46:<br>
Compile your bootloader code using KDS. Connect your KL46 board to your computer via a debug probe (e.g., J-Link or OpenSDA). Use the KDS debugger to flash your compiled bootloader binary onto the KL46’s flash memory.<br>

4.3 Install Hercules 3.2.8 for UART Communication:<br>
Download and install Hercules 3.2.8, a versatile terminal program for serial communication. Configure the COM port settings (e.g., COM1, COM2) in Hercules to match the one connected to your KL46 board. Set the baud rate to 115200 (or the rate you’ve configured in your bootloader).<br>
![Screenshot 2024-09-10 164745](https://github.com/user-attachments/assets/87c6c744-6367-462a-b1de-d99fc1076799)<br>

4.4 Enter Bootloader Mode:<br>
Press and hold Switch 3, Simultaneously press the Reset button. You’ll notice that the red LED on the board lights up. At this point, the bootloader should start running, and it will communicate with Hercules over the UART connection.<br>
![frdm-kl46z-components](https://github.com/user-attachments/assets/4713a631-cb3b-4f2e-8a53-f59c78521fa7)<br>

4.5 Observe Output in Hercules:<br>
In the Hercules terminal, you should see the output sent by your bootloader. Follow any instructions provided by my bootloader.

## 5. Notes
 - Under no circumstances should you press and hold the **Reset button** while simultaneously plugging in the power for the MKL46 board. Doing so would erase the debug firmware, and your computer would no longer recognize the board. In this situation, you’ll need to update the debug firmware.

## 6. Authors
 - Nguyen Dang Nhu Tri

## 7. License
 - The project is distributed under the MIT License. Refer to the LICENSE file for more details.
