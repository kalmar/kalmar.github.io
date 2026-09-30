# Anton Romankov

**Senior Backend Engineer / Team Lead · Java · Distributed Systems · Data Platforms**

Batumi, Georgia · [anton.romankov@gmail.com](mailto:anton.romankov@gmail.com) · [linkedin.com/in/kalmarmaster](https://www.linkedin.com/in/kalmarmaster/) · [t.me/kalmarmaster](https://t.me/kalmarmaster)

---

## Summary

Senior backend engineer and team lead with **13+ years** of building production systems, from low-level C++ to high-load Java microservices. I've maintained and evolved the core of an identity-verification (KYC) platform and designed a server-driven UI for a consumer app, a visual data platform for one of the world's largest digital banks, and network automation for Cisco's enterprise products.

I lead teams and still write code. I'm most useful where a system has to be rethought, not just maintained: I've rewritten search, storefront, OCR, and payroll engines, making each one faster, simpler, and easier to extend. My degree in applied mathematics shows in how I approach algorithms and data. I use AI in my daily work, from integrating LLMs into products with LangChain4j to working with coding agents such as Claude Code and Codex.

## Technical Skills

| | |
|---|---|
| **Languages** | Java, C++, Python |
| **Backend** | Spring, Jakarta EE, Micronaut, Hibernate, REST, Event-Driven Architecture |
| **Data & Streaming** | PostgreSQL, Greenplum, MongoDB, Redis, Elasticsearch, Cassandra, Kafka, RabbitMQ, Apache Flink, Apache Calcite, Hadoop, Iceberg, Parquet, S3 |
| **AI / LLM** | LangChain4j, OCR + LLM Document Processing, Claude Code, Codex |
| **Infrastructure** | Docker, Kubernetes, GitLab CI/CD, GitHub Actions, TeamCity, Jenkins, Gradle, Maven, CMake, Linux |
| **Leadership** | Team Leadership, System Design, Code Review, Mentoring, Technical Roadmap |

## Professional Experience

### [Sumsub](https://sumsub.com/) · Backend Engineer / Team Lead
*Jun 2024 – Jun 2026 · Batumi, Georgia*

Sumsub is a global identity-verification and anti-fraud platform. I was part of the core team that owns the KYC pipeline, the product's main revenue flow.

- Owned the development and reliability of the KYC verification pipeline end to end: architecture, new features, production incidents, and large-scale refactoring.
- **Brought NFC chip verification into the KYC pipeline**: designed and implemented cryptographic-grade validation of chip data in biometric passports and ID cards, strengthening fraud protection.
- **Rebuilt the in-house OCR parsing engine**, combining OCR with LLM-based search (LangChain4j) to extract data from applicant documents more accurately and make the engine easier to extend.
- **Rewrote the moderator salary engine**, replacing legacy logic with a transparent, maintainable calculation model.

*Stack: Java, Jakarta EE, MongoDB, Redis, S3, Kafka, Docker, Kubernetes, GitLab CI/CD, LangChain4j*

### [ToYou](https://toyou.io/en) (via [Setronica](https://setronica.com/)) · Backend Engineer / Team Lead
*Jun 2023 – Aug 2024 · Batumi, Georgia*

ToYou is a super-app for food and grocery delivery in Saudi Arabia.

- **Led the team** responsible for the backend-for-frontend facade of the mobile app: personalized product catalog, search, and merchant storefronts.
- **Designed a custom server-driven UI protocol** that lets the backend compose mobile app screens, so product teams ship UI changes and experiments without waiting for app store releases.
- **Cut PostgreSQL load by 25%** by redesigning the search and merchant storefront engines behind the high-traffic app, improving response times under peak load.

*Stack: Java, Spring, PostgreSQL, Elasticsearch, Redis, Hibernate, Kafka, RabbitMQ, Kubernetes, GitHub Actions*

### [Tinkoff](https://www.tinkoff.ru/) · Senior Software Engineer
*Aug 2021 – Jun 2023 · Novosibirsk, Russia / Antalya, Turkey*

Tinkoff is one of the world's largest fully digital banks.

- Built the backend of an **internal data discovery and preparation platform** (a Dremio-like product) where analysts build ETL and analytics pipelines in a visual graph editor instead of writing SQL.
- **Designed the query engine**, built on Apache Calcite, that turns visual graphs into optimized SQL.
- **Built a Greenplum extension** that exposes Parquet/Iceberg data lake tables as native SQL tables, connecting the bank's warehouse to its lakehouse and giving analysts SQL access to the data lake without copying data.
- Developed **real-time streaming pipelines** on Apache Flink.

*Stack: Java, Spring, Micronaut, Apache Calcite, Apache Flink, PostgreSQL, Greenplum, Cassandra, Hadoop, Iceberg, Parquet, Kubernetes*

### [Cisco](https://cisco.com) (through [Xored](https://xored.com)) · Senior Software Engineer
*Nov 2016 – Aug 2021 · Novosibirsk, Russia*

- Developed **Cisco Prime Infrastructure** and **Cisco DNA Center**, enterprise platforms that manage network infrastructure for Cisco customers worldwide.
- **Owned the configuration engine** that translates high-level network models into device configurations and deploys them to fleets of managed devices.
- Worked directly with Cisco engineering teams over five years of continuous collaboration.

*Stack: Java, Spring, PostgreSQL, Hibernate, Docker, Kubernetes*

### [ICT SB RAS](http://www.ict.nsc.ru/en) · Technical Lead (part-time)
*Sep 2015 – Dec 2016 · Novosibirsk, Russia*

- **Led the development of a client-server seismic monitoring system** for RusHydro, Russia's largest hydropower company. The system runs on critical infrastructure and is in operation at the **Zeya Dam** and the **Nizhnekamsk Hydroelectric Station**.
- Designed the architecture: a C++ server and a Qt desktop client communicating over Protobuf/Asio.
- Co-authored a [peer-reviewed paper](http://link.springer.com/article/10.3103/S0747923918040114) on the system.

*Stack: C++, Qt, Protobuf, Asio, SQLite, CMake, Linux*

### [WiseMo](https://www.wisemo.com/) (through [Noveo](https://noveogroup.com/)) · Software Engineer
*Jun 2013 – Nov 2016 · Novosibirsk, Russia*

- Developed a **cross-platform remote desktop product** (host and client) connecting any device to any other across Windows, Windows CE, Android, iOS, and Chrome PNaCl.
- Built shared C++ core logic and integrated it into the Android client through JNI.

*Stack: C++, Java, JNI, CMake, Gradle*

### [Intel](https://intel.com) · IT Intern
*Mar 2007 – Dec 2007, Aug 2010 – Mar 2012 · Novosibirsk, Russia*

- Automated software deployment and virtualization across the data center using Bash, Python, and PowerShell; supported servers and workstations.

## Education

### [Novosibirsk State University](https://nsu.ru) · B.Sc. in Mathematics
*2008 – 2013 · Faculty of Mechanics and Mathematics, Numerical Analysis*

- Thesis: a high-accuracy Runge–Kutta/WENO method (fourth order in time, fifth order in space) for modeling wave propagation in saturated elastic porous media. [Published](http://link.springer.com/article/10.1134/S1995423914030045) in a peer-reviewed journal.
- Studied Applied Informatics at the IT Department of the same university (2004 – 2007).

## Publications

- A Runge–Kutta/WENO method for small-amplitude wave propagation in a saturated elastic porous medium. [DOI: 10.1134/S1995423914030045](http://link.springer.com/article/10.1134/S1995423914030045)
- Paper on the seismic monitoring system built for RusHydro (Seismic Instruments, 2018). [DOI: 10.3103/S0747923918040114](http://link.springer.com/article/10.3103/S0747923918040114)

## Languages

- **English**: B2 (professional working proficiency)
- **Russian**: Native
