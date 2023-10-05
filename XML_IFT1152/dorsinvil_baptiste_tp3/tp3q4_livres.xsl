<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema" exclude-result-prefixes="xs" version="2.0">
    <xsl:output method="html" encoding="utf-8"/>

    <xsl:template match="/">
        <html>
            <head>
                <title>Nouveau Site Web</title>
                <style>
                    table,
                    td,
                    th {
                        border: 1px solid;
                    }</style>
            </head>
            <body>
                <xsl:apply-templates/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="livres">
        <h1>Mes livres - Question 4</h1>
        <table>
            <tr style="background: #9acd32">
                <th>Titre</th>
                <th>Langue</th>
                <th>CD inclus</th>

                <th>Auteurs</th>

            </tr>
            <xsl:apply-templates/>
        </table>
    </xsl:template>

    <xsl:template match="livre">
        <tr>
            <xsl:attribute name="style"> <xsl:choose>
                <xsl:when test="@langue = 'francais'"> background-color:#909090</xsl:when>
                <xsl:when test="@langue = 'anglais'"> background-color:#C0C0C0 </xsl:when>
                
            </xsl:choose>
            </xsl:attribute>
            <xsl:apply-templates select="titre"/>
            <td> 

                <xsl:value-of select="livres/livre"/>
                <xsl:value-of select="@langue"/>
                
            </td> 
            
            <xsl:apply-templates select="cd_inclus"/>
            
            <xsl:apply-templates select="auteurs"/>


        </tr>
    </xsl:template>

    <xsl:template match="titre ">
        <td>
            <em>
                <xsl:value-of select="text()"/>

            </em>

        </td>


    </xsl:template>
    <xsl:template match="cd_inclus">

        <td>
            <xsl:attribute name="style"> 
                <xsl:if test="'oui'"> color:yelow</xsl:if>
              
                
            
            </xsl:attribute>
            <xsl:attribute name="style"> 
                <xsl:if test="'oui'"> color:blue</xsl:if>
                
                
                
            </xsl:attribute>
            <xsl:value-of select="text()"/>
        </td>

    </xsl:template>

    <xsl:template match="auteurs">

        <td>
            <xsl:for-each select="auteur">

                <ul>
                    <li>
                        <xsl:value-of select="prenom"/>
                        <xsl:text> </xsl:text>
                        <xsl:value-of select="nom"/>
                    </li>

                </ul>
            </xsl:for-each>
        </td>
    </xsl:template>
    <xsl:template match="nom">

        <td>
            <li>
                <xsl:value-of select="text()"/>
            </li>
        </td>
    </xsl:template>

    <xsl:template match="contenu">
        <td>
            <xsl:value-of select="text()"/>
        </td>
    </xsl:template>
    <xsl:template match="langue">
        <td>
            <xsl:value-of select="text()"/>
        </td>
    </xsl:template>
    <xsl:template match="* | text()"> </xsl:template>


</xsl:stylesheet>
