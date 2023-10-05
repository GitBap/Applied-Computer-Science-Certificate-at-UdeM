-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  lun. 14 nov. 2022 à 16:15
-- Version du serveur :  10.4.10-MariaDB
-- Version de PHP :  7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `bdboutique`
--

-- --------------------------------------------------------

--
-- Structure de la table `articles`
--

DROP TABLE IF EXISTS `articles`;
CREATE TABLE IF NOT EXISTS `articles` (
  `ida` int(11) NOT NULL AUTO_INCREMENT,
  `nomarticle` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `description` text COLLATE utf8_unicode_ci NOT NULL,
  `imageart` varchar(200) COLLATE utf8_unicode_ci NOT NULL,
  `categorie` varchar(3) COLLATE utf8_unicode_ci NOT NULL,
  `qteinventaire` int(11) NOT NULL,
  `seuil` int(11) NOT NULL,
  `prix` float NOT NULL,
  PRIMARY KEY (`ida`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Déchargement des données de la table `articles`
--

INSERT INTO `articles` (`ida`, `nomarticle`, `description`, `imageart`, `categorie`, `qteinventaire`, `seuil`, `prix`) VALUES
(17, 'Écouteurs', 'Bons écouteurs', 'bff828162ad159ba45a59f57f7eb352cde01bc52.webp', 'arb', 30, 15, 125),
(20, 'Chaise de bureau', 'Très jolie chaise en cuir', 'f6ba0dcba6c59477018a4c82e6351d114687b3e2.webp', 'arb', 10, 5, 180),
(21, 'Lampe de bureau', 'Lampe de bureau moderne', '58afd3caaa4b120e0873b90fc74fae15c1836adf.webp', 'arb', 15, 5, 80),
(22, 'Chaise de bureau', 'tres confortable.', 'ea3c49036ce27548f1caed4cfc06ea5cae25fef2.webp', 'arb', 10, 5, 125),
(23, 'Écouteurs type 2', 'Bons écouteurs haute qualité', 'edf978c2c217ef7b906e6d3d327cffe3136d96b3.webp', 'arb', 10, 5, 80),
(24, 'Chemises type 1', 'Chemises de couleurs diverses', 'dffb2effb8e1efbf8c321578f8df32d039fde21c.webp', 'meu', 30, 15, 80);

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
(11, 'mbowou@gmail.com', 'RDG', 'M', 'A');

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
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Déchargement des données de la table `membres`
--

INSERT INTO `membres` (`idm`, `nom`, `prenom`, `courriel`, `sexe`, `datenaissance`) VALUES
(11, 'MBOWOU', 'Ibrahim', 'mbowou@gmail.com', 'M', '2002-02-05');

-- --------------------------------------------------------

--
-- Structure de la table `panier`
--

DROP TABLE IF EXISTS `panier`;
CREATE TABLE IF NOT EXISTS `panier` (
  `idpanier` int(11) NOT NULL AUTO_INCREMENT,
  `idm` int(11) NOT NULL,
  `ida` int(11) NOT NULL,
  `quantite` int(11) NOT NULL,
  `dates` datetime NOT NULL,
  PRIMARY KEY (`idpanier`),
  KEY `idm` (`idm`),
  KEY `ida` (`ida`)
) ENGINE=MyISAM AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `panier`
--

INSERT INTO `panier` (`idpanier`, `idm`, `ida`, `quantite`, `dates`) VALUES
(13, 11, 23, 1, '2022-11-14 03:28:51'),
(12, 11, 20, 2, '2022-11-14 03:28:44'),
(11, 11, 17, 2, '2022-11-14 03:28:38');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
