# CSSCHH - Correlated Space-Saving with Correlated Heavy Hitters

CSSCHH is an implementation of the Space-Saving algorithm extended to detect correlated heavy hitters in a data stream. This project is developed in C++ and aims to provide an efficient and scalable solution for identifying frequently occurring items and correlated pairs.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Configuration](#configuration)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Space-Saving is a streaming algorithm designed for identifying frequent items in a data stream with limited memory. CSSCHH extends this concept to detect correlated heavy hitters, providing insights into relationships between items.

## Features

- Efficient Space-Saving algorithm implementation
- Detection of correlated heavy hitters in secondary data streams
- Configuration options for adjusting algorithm parameters
- User-friendly interface for easy integration

## Getting Started

### Prerequisites

- C++ compiler with C++14 support
- xxhash library (install using package manager or brew)

### Installation and execuation

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/CSSCHH.git
cd CSSCHH
make
./main

