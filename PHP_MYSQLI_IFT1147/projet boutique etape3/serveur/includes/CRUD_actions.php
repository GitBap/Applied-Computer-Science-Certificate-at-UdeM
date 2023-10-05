<tr>
    <td>
        <span>
            <input type="checkbox" id="opt" name="options[]" value="<?php echo $article["id"][$i];?>" />
        </span>
    </td>

    <td>
        <?php echo $i; ?>
    </td>
    
    <td>
       <img src= "../../images_articles/<?php echo $article["image"][$i];?>" height="50px" width="50px">
    </td>
    
    <td>
        <?php echo $article["nom"][$i]; ?>
    </td>
    
    <td>
        <?php echo  $article["description"][$i]; ?>
    </td>
    
    <td>
        <?php echo  $article["categorie"][$i]; ?>
    </td>
    
    <td>
        <?php echo  $article["prix"][$i]; ?>
    </td>
    
    <td>
        <?php echo  $article["quantite"][$i]; ?>
    </td>

    <td>
        <?php echo  $article["seuil"][$i]; ?>
    </td>
</tr>