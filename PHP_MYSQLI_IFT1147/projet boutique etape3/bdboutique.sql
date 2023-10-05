-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le : mar. 13 déc. 2022 à 21:32
-- Version du serveur :  5.7.31
-- Version de PHP : 7.3.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `bdboutique`
--

-- --------------------------------------------------------

--
-- Structure de la table `articles`
--

DROP TABLE IF EXISTS `articles`;
CREATE TABLE IF NOT EXISTS `articles` (
  `ida` int(11) NOT NULL AUTO_INCREMENT,
  `nomarticle` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `description` text COLLATE utf8_unicode_ci NOT NULL,
  `imageart` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `categorie` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `qteinventaire` int(11) NOT NULL,
  `seuil` int(11) NOT NULL,
  `prix` float NOT NULL,
  PRIMARY KEY (`ida`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Déchargement des données de la table `articles`
--

INSERT INTO `articles` (`ida`, `nomarticle`, `description`, `imageart`, `categorie`, `qteinventaire`, `seuil`, `prix`) VALUES
(36, 'ordinateur', 'core i5', '6e7a44f7a52740274437922be6e9e23ce9713f2b.webp', 'ord', 10, 3, 150000),
(39, 'deskjet1015', 'imprimente couleurs 5 copies par minutes', '2b3974daabd4b63c0a613aef972a48889293efb3.jpg', 'imp', 20, 3, 70000),
(40, 'Appareil photo', 'fijitsu 1080mp', '7f2fb8566ff69da4c042b7b032b857c532eae4c7.jpg', 'app', 25, 4, 15000);

-- --------------------------------------------------------

--
-- Structure de la table `categories`
--

DROP TABLE IF EXISTS `categories`;
CREATE TABLE IF NOT EXISTS `categories` (
  `idcateg` int(11) NOT NULL AUTO_INCREMENT,
  `categ` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`idcateg`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Déchargement des données de la table `categories`
--

INSERT INTO `categories` (`idcateg`, `categ`) VALUES
(1, 'Articles de bureau'),
(2, 'Imprimantes'),
(3, 'Meubles'),
(4, 'Ordinateurs'),
(5, 'Appareils photo'),
(6, 'Photocopieurs'),
(7, 'Toutes');

-- --------------------------------------------------------

--
-- Structure de la table `connexion`
--

DROP TABLE IF EXISTS `connexion`;
CREATE TABLE IF NOT EXISTS `connexion` (
  `idm` int(11) NOT NULL,
  `courriel` varchar(256) COLLATE utf8_unicode_ci NOT NULL,
  `pass` varchar(12) COLLATE utf8_unicode_ci NOT NULL,
  `role` varchar(1) COLLATE utf8_unicode_ci DEFAULT 'M',
  `statut` varchar(1) COLLATE utf8_unicode_ci DEFAULT 'A'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Déchargement des données de la table `connexion`
--

INSERT INTO `connexion` (`idm`, `courriel`, `pass`, `role`, `statut`) VALUES
(1, 'admin@boutique.com', '12345', 'A', 'A'),
(3, 'antonio@gmail.com', '12345', 'M', 'A'),
(0, 'mbowou@gmail.com', '123', 'M', 'A'),
(4, 'mbowou@gmail.com', '123', 'M', 'A'),
(5, 'mbowou@gmail.com', '123456', 'M', 'A'),
(6, 'mbowou2@gmail.com', '123', 'M', 'A'),
(7, '547577@gmail.com', '111', 'M', 'A');

-- --------------------------------------------------------

--
-- Structure de la table `membres`
--

DROP TABLE IF EXISTS `membres`;
CREATE TABLE IF NOT EXISTS `membres` (
  `idm` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `prenom` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `courriel` varchar(256) COLLATE utf8_unicode_ci NOT NULL,
  `sexe` varchar(1) COLLATE utf8_unicode_ci DEFAULT NULL,
  `datenaissance` date DEFAULT NULL,
  PRIMARY KEY (`idm`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Déchargement des données de la table `membres`
--

INSERT INTO `membres` (`idm`, `nom`, `prenom`, `courriel`, `sexe`, `datenaissance`) VALUES
(1, 'Bond', 'James', 'admin@boutique.com', 'M', '1968-02-16'),
(3, 'Antonio', 'Tavares', 'antonio@gmail.com', 'M', '2022-03-03'),
(4, 'Mbowou', 'Ordinateur', 'mbowou@gmail.com', 'M', '2022-12-13'),
(5, 'Mbowou', 'Ibrahim', 'mbowou@gmail.com', 'M', '2022-12-15'),
(6, 'Mbowou2', 'Ibrahim2', 'mbowou2@gmail.com', 'M', '2002-02-04'),
(7, 'Mbowou3', 'Ordinateur3', '547577@gmail.com', 'M', '2022-12-01');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
