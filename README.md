# ✨ Voice Controlled Wheelchair

This project builds a **smart wheelchair that moves on simple voice commands**, designed to enhance independence and mobility for differently-abled individuals.

---

## 🎯 Project Objective
- Create a wheelchair that listens and responds to voice commands like **"forward," "backward," "left," "right," "stop"**.
- Provide an affordable, intuitive alternative to joystick-controlled systems.
- Design with safety, reliability, and ease of customization in mind.

---

## 🛠️ Tech Stack
| Layer                  | Technology Used                    |
|-------------------------|-----------------------------------|
| **Voice Recognition**   | Voice Recognition Module V3       |
| **Microcontroller**     | Arduino Nano                     |
| **Motor Control**       | BTS7960 Motor Driver (for DC motors) |
| **Power & Protection**  | Battery packs, protective diodes |
| **Programming**         | Arduino C++                      |

---

## 🚀 How It Works
1. 🎤 **Voice commands** are captured by the **Voice Recognition Module V3**, trained to recognize specific keywords.
2. 🧠 The module sends recognized command signals to the **Arduino Nano**.
3. ⚡ The Arduino processes these inputs and directs the **BTS7960 motor driver**, which controls the wheelchair’s motors to move in the desired direction.
4. 🛑 Safety overrides ensure quick stops if unclear commands or errors occur.

---

## 📚 Key Features
✅ Hands-free operation — crucial for users with limited upper-body movement.  
✅ Local voice processing (no internet required).  
✅ Manual override switches for immediate stop and fail-safe control.  
✅ Modular design — can be adapted to different wheelchair bases or motors.

---

## 🚀 Challenges & What I Learned
- Dealt with **noise sensitivity** in the voice module by tuning thresholds and providing clear voice samples.
- Learned robust **motor current handling** and how to avoid back EMF damage using protective diodes.
- Reinforced the importance of **designing for real user safety** when working with mobility aids.

---

## 🌱 Future Enhancements
- Integrate **ultrasonic sensors** for automatic obstacle detection and avoidance.
- Use **machine learning speech models** for more natural voice commands.
- Build a companion **mobile app** for hybrid manual control.

---

## 🙋 About Me
👋 Hi, I’m **Chandana H H**, an Electronics and Communication Engineer passionate about leveraging technology to build **accessible, life-enhancing solutions**.

📬 Reach me at **[chandanahh684@gmail.com](mailto:chandanahh684@gmail.com)**  
🔗 Connect on [LinkedIn](https://www.linkedin.com/in/chandana-h-h-145909229/)

---

⭐ **If you find this project inspiring, please give it a star on GitHub!** ⭐
