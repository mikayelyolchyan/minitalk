
<a name="readme-top"></a>
<div align="center">

  <!-- Project Name -->
  <h1>Minitalk</h1>

  <!-- Short Description -->
  <p align="center">
	  <b>Simple Client-Server communication in C</b><br>
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-mandatory-part">🔷 Mandatory Part</a>
    <span> · </span>
	  <a href="#-bonus-part">🌟 Bonus Part</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
  </h3>
</div>

---

<p align="center">
  <img src="gifs/100000char.gif" width="1600"/>
</p>

## 📜 About Project

> 42 School Minitalk project is a simple communication program using UNIX signals. \
> The project is designed to introduce the basics of signal handling and inter-process communication.

For detailed information, refer to the [**subject of this project**](en.subject.pdf).

	🚀 TLDR: This project is an introduction to the basics of signal handling and inter-process communication.
    Learn about sending and receiving signals, and managing communication between processes.

> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 🔷 Mandatory Part

#### The subject describes the application as follows:

* The application consists of a server and a client.
* The server receives messages from the client and displays them.
* The client sends messages to the server using UNIX signals.
* The server acknowledges the receipt of each message.

## 🌟 Bonus Part

#### The subject describes the application as follows:

* The server must acknowledge each received message by sending a signal to the
client.
* Unicode characters support!

## 👨‍💻 Usage

`./server`

`./client <server_pid> <message>`

* **
