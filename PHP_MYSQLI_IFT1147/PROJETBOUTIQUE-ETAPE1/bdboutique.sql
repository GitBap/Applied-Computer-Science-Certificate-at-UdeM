-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Sep 27, 2022 at 11:29 AM
-- Server version: 10.4.10-MariaDB
-- PHP Version: 7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bdboutique`
--

-- --------------------------------------------------------

--
-- Table structure for table `article`
--

DROP TABLE IF EXISTS `article`;
CREATE TABLE IF NOT EXISTS `article` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `img` varchar(120) COLLATE utf8_bin NOT NULL,
  `categorie` varchar(20) COLLATE utf8_bin NOT NULL,
  `article` varchar(40) COLLATE utf8_bin NOT NULL,
  `description` text COLLATE utf8_bin NOT NULL,
  `prix` double NOT NULL,
  `qte` int(11) NOT NULL,
  `seuil` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `article`
--

INSERT INTO `article` (`id`, `img`, `categorie`, `article`, `description`, `prix`, `qte`, `seuil`) VALUES
(1, 'products-1.jpg', 'Laptops', 'Macbook Pro 15inch', 'ordinateur de bureau professionnel', 1500, 10, 2),
(2, 'products-2.jpg', 'outils de bureau', 'Table de travail', 'Table de bureau', 300, 10, 1),
(3, 'products-3.jpg', 'Laptops', 'Macbook Pro 15inch', 'MacBook professionnel 2015', 1500, 25, 5),
(4, 'products-4.jpg', 'Laptops', 'Macbook Pro 15inch', 'Mackbook pro 2015 ', 1500, 25, 5),
(5, 'products-1.jpg', 'Laptops', 'Macbook Pro 15inch', 'Mackbook pro 2015 ', 1500, 25, 5),
(8, 'image_search_1588504053938.jpg', '7', 'chaise', 'xhaise pour cadre', 100, 5, 2);

-- --------------------------------------------------------

--
-- Table structure for table `connexion`
--

DROP TABLE IF EXISTS `connexion`;
CREATE TABLE IF NOT EXISTS `connexion` (
  `Idcm` int(11) NOT NULL,
  `courriel` varchar(25) COLLATE utf8_bin NOT NULL,
  `password` varchar(10) COLLATE utf8_bin NOT NULL,
  `role` varchar(10) COLLATE utf8_bin NOT NULL,
  `statut` varchar(10) COLLATE utf8_bin NOT NULL,
  KEY `Idcm` (`Idcm`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `connexion`
--

INSERT INTO `connexion` (`Idcm`, `courriel`, `password`, `role`, `statut`) VALUES
(2, 'bobo@gmail.com', '12345', 'M', 'A'),
(5, 'rico@gmail.com', '123456', 'M', 'A'),
(6, 'rico@gmail.com', '123456', 'M', 'I'),
(7, 'mugue@gmail.com', '1234567', 'M', 'I'),
(8, 'djomo@gmail.com', '123456', 'M', 'A'),
(6, 'lemo@gmail.com', '123456', 'A', 'I');

-- --------------------------------------------------------

--
-- Table structure for table `menbres`
--

DROP TABLE IF EXISTS `menbres`;
CREATE TABLE IF NOT EXISTS `menbres` (
  `Idm` int(11) NOT NULL,
  `nom` varchar(30) COLLATE utf8_bin NOT NULL,
  `prenom` varchar(20) COLLATE utf8_bin NOT NULL,
  `courriel` varchar(25) COLLATE utf8_bin NOT NULL,
  `sexe` varchar(10) COLLATE utf8_bin NOT NULL,
  `date_naiss` date NOT NULL,
  PRIMARY KEY (`Idm`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `menbres`
--

INSERT INTO `menbres` (`Idm`, `nom`, `prenom`, `courriel`, `sexe`, `date_naiss`) VALUES
(1, 'MANGA', 'pierre', 'pierre@gmail.com', 'masculin', '2000-05-10'),
(2, 'Djomo', 'gide', 'bobo@gmail.com', 'on', '2001-05-21'),
(3, 'DODO', 'mado', 'mado@gmail.com', 'feminin', '2002-03-13'),
(4, 'kenfack', 'manuella', 'kenfack@gmail.com', 'feminin', '1998-08-17'),
(5, 'Lemogo', 'ric daniel', 'rico@gmail.com', 'masculin', '2001-03-12'),
(6, 'Lemogo', 'ric daniel', 'rico@gmail.com', 'masculin', '2001-03-12'),
(7, 'Mugue', 'Franck', 'mugue@gmail.com', 'feminin', '2000-05-26'),
(8, 'Djomo', 'gide', 'djomo@gmail.com', 'masculin', '1998-01-20');

-- --------------------------------------------------------

--
-- Table structure for table `panier`
--

DROP TABLE IF EXISTS `panier`;
CREATE TABLE IF NOT EXISTS `panier` (
  `idmb` int(11) NOT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ida` int(11) NOT NULL,
  `quantite` int(11) NOT NULL,
  `date` date NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idmb` (`idmb`),
  KEY `ida` (`ida`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `connexion`
--
ALTER TABLE `connexion`
  ADD CONSTRAINT `connexion_ibfk_1` FOREIGN KEY (`Idcm`) REFERENCES `menbres` (`Idm`);

--
-- Constraints for table `panier`
--
ALTER TABLE `panier`
  ADD CONSTRAINT `panier_ibfk_1` FOREIGN KEY (`idmb`) REFERENCES `menbres` (`Idm`),
  ADD CONSTRAINT `panier_ibfk_2` FOREIGN KEY (`ida`) REFERENCES `article` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
