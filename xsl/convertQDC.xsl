<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:template match="/">
        <div><table cellspacing="3" cellpadding="3"><tbody>
            <tr><th colspan="3"><h3 class="islandora-obj-details-metadata-title">Metadata <span class="islandora-obj-details-dsid">(DC)</span></h3></th></tr>
            <xsl:for-each select="/*/*">
                <xsl:variable name="FULLFIELD" select="name()"/>
                <xsl:variable name="FIELD" select="local-name()"/>
                <xsl:variable name="DATA" select="text()"/>
                <xsl:if test="$DATA != ' '">
                    <tr><td><strong><xsl:value-of select="local-name()"/></strong></td><td><xsl:value-of select="text()"/>
                        <xsl:for-each select="*">
                            <div>
                                <xsl:value-of select="local-name()"/> =  <xsl:value-of select="text()"/>
                            </div>
                        </xsl:for-each>
                    </td></tr>
                </xsl:if>
            </xsl:for-each>
        </tbody></table></div>
    </xsl:template>
</xsl:stylesheet>
